
from django.shortcuts import render, redirect, get_object_or_404
from django.contrib.auth.decorators import login_required
from django.contrib.auth.models import User
from django.contrib.auth import login, logout, authenticate

from .models import Post, Comment, Like, Follow
from .forms import PostForm, CommentForm
from django.contrib.auth import login
from .forms import RegisterForm
from django.db.models import Q
from .models import Post, Comment, Like, Follow, Category
from django.contrib.auth.models import User
from django.core.paginator import Paginator
from django.contrib import messages





def home(request):

    latest_posts = Post.objects.all().order_by('-created_at')[:5]
    recent_comments = Comment.objects.order_by('-created_at')[:5]
    posts = Post.objects.all().order_by('-created_at')
    categories = Category.objects.all()

    # # Search

    search = request.GET.get('search')

    if search:
        posts = posts.filter(
            Q(title__icontains=search) |
            Q(content__icontains=search) |
            Q(tags__icontains=search)
    )

    # Category Filter
    category = request.GET.get('category')
    if category:
        posts = posts.filter(category__id=category)

    # Author Filter
    author = request.GET.get('author')
    if author:
        posts = posts.filter(author__username=author)

    # Date Filter
    start_date = request.GET.get('start_date')
    end_date = request.GET.get('end_date')

    if start_date:
        posts = posts.filter(
            created_at__date__gte=start_date
        )

    if end_date:
        posts = posts.filter(
            created_at__date__lte=end_date
        )

    # Pagination
    paginator = Paginator(posts, 5)

    page_number = request.GET.get('page')

    posts = paginator.get_page(page_number)

    users = User.objects.all()

    return render(
        request,
        'blog/home.html',
        {
            'posts': posts,
            'categories': categories,
            'users': users,
            'latest_posts': latest_posts,
            'recent_comments': recent_comments,
        }
    )

def post_detail(request, pk):
    post = get_object_or_404(Post, pk=pk)
    comments = Comment.objects.filter(post=post).order_by('-created_at')
    form = CommentForm()
    return render(
        request,
        'blog/post_detail.html',
        {
            'post': post,
            'comments': comments,
            'form': form
        }
    )


@login_required
def create_post(request):
    if request.method == 'POST':
        form = PostForm(request.POST, request.FILES)
        if form.is_valid():
            post = form.save(commit=False)
            post.author = request.user
            post.save()
            return redirect('home')
    else:
        form = PostForm()

    return render(request, 'blog/create_post.html', {'form': form})


@login_required
def edit_post(request, pk):
    post = get_object_or_404(Post, pk=pk, author=request.user)

    if request.method == 'POST':
        form = PostForm(request.POST, request.FILES, instance=post)
        if form.is_valid():
            form.save()
            return redirect('post_detail', pk=pk)
    else:
        form = PostForm(instance=post)

    return render(request, 'blog/create_post.html', {'form': form})


@login_required
def delete_post(request, pk):
    post = get_object_or_404(Post, pk=pk, author=request.user)

    if request.method == 'POST':
        post.delete()
        return redirect('home')

    return render(request, 'blog/delete_post.html', {'post': post})


@login_required
def add_comment(request, pk):
    post = get_object_or_404(Post, pk=pk)

    if request.method == 'POST':
        form = CommentForm(request.POST)
        if form.is_valid():
            comment = form.save(commit=False)
            comment.user = request.user
            comment.post = post
            comment.save()

    return redirect('post_detail', pk=pk)


@login_required
def like_post(request, pk):
    post = get_object_or_404(Post, pk=pk)
    like, created = Like.objects.get_or_create(user=request.user, post=post)

    if not created:
        like.delete()

    return redirect('post_detail', pk=pk)


@login_required
def follow_author(request, user_id):
    author = get_object_or_404(User, id=user_id)
    follow, created = Follow.objects.get_or_create(
        follower=request.user,
        following=author
    )

    if not created:
        follow.delete()

    return redirect('home')


@login_required
def edit_comment(request, pk):
    comment = get_object_or_404(Comment, pk=pk, user=request.user)

    if request.method == 'POST':
        form = CommentForm(request.POST, instance=comment)
        if form.is_valid():
            form.save()
            return redirect('post_detail', pk=comment.post.id)
    else:
        form = CommentForm(instance=comment)

    return render(request, 'blog/edit_comment.html', {'form': form})

@login_required
def delete_comment(request, pk):
    comment = get_object_or_404(
        Comment,
        pk=pk,
        user=request.user
    )

    post_id = comment.post.id

    if request.method == 'POST':
        comment.delete()
        return redirect(
            'post_detail',
            pk=post_id
        )

    return render(
        request,
        'blog/delete_comment.html',
        {
            'comment': comment
        }
    )
    
def register(request):

    if request.method == 'POST':

        form = RegisterForm(request.POST)

        if form.is_valid():

            user = form.save()

            login(request, user)

            return redirect('home')

        else:
            print(form.errors)

    else:
        form = RegisterForm()

    return render(
        request,
        'registration/register.html',
        {'form': form}
    )
    
    
def user_login(request):

    if request.method == 'POST':

        username = request.POST['username']
        password = request.POST['password']

        user = authenticate(
            request,
            username=username,
            password=password
        )

        if user:
            login(request, user)
            return redirect('home')

    return render(
        request,
        'registration/login.html'
    )


def user_logout(request):
    logout(request)
    return redirect('login')