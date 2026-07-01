# # from django import forms
# # from django.contrib.auth.models import User
# # from django.contrib.auth.forms import UserCreationForm

# # from .models import Post, Comment


# # # User Registration Form
# # class UserRegisterForm(UserCreationForm):

# #     email = forms.EmailField(required=True)

# #     class Meta:
# #         model = User

# #         fields = [
# #             'username',
# #             'email',
# #             'password1',
# #             'password2'
# #         ]


# # # Blog Post Form
# # class PostForm(forms.ModelForm):

# #     class Meta:
# #         model = Post

# #         fields = [
# #             'title',
# #             'category',
# #             'content',
# #             'image',
# #             'tags'
# #         ]

# #         widgets = {
# #             'title': forms.TextInput(
# #                 attrs={
# #                     'class': 'form-control'
# #                 }
# #             ),

# #             'category': forms.Select(
# #                 attrs={
# #                     'class': 'form-select'
# #                 }
# #             ),

# #             'content': forms.Textarea(
# #                 attrs={
# #                     'class': 'form-control',
# #                     'rows': 8
# #                 }
# #             ),

# #             'tags': forms.TextInput(
# #                 attrs={
# #                     'class': 'form-control',
# #                     'placeholder': 'Python,Django,Web'
# #                 }
# #             ),
# #         }


# # # Comment Form
# # class CommentForm(forms.ModelForm):

# #     class Meta:
# #         model = Comment

# #         fields = ['comment']

# #         widgets = {
# #             'comment': forms.Textarea(
# #                 attrs={
# #                     'class': 'form-control',
# #                     'rows': 3,
# #                     'placeholder': 'Write your comment...'
# #                 }
# #             )
# #         }



# from django import forms
# from django.contrib.auth.models import User
# from django.contrib.auth.forms import UserCreationForm

# from .models import Post, Comment


# class RegisterForm(UserCreationForm):
#     email = forms.EmailField()

#     class Meta:
#         model = User
#         fields = [
#             'username',
#             'email',
#             'password1',
#             'password2'
#         ]


# class PostForm(forms.ModelForm):
#     class Meta:
#         model = Post
#         fields = [
#             'title',
#             'category',
#             'content',
#             'image'
#         ]


# class CommentForm(forms.ModelForm):
#     class Meta:
#         model = Comment
#         fields = ['comment']



from django import forms
from django.contrib.auth.models import User
from django.contrib.auth.forms import UserCreationForm

from .models import Post, Comment


class RegisterForm(UserCreationForm):
    email = forms.EmailField()

    class Meta:
        model = User
        fields = [
            'username',
            'email',
            'password1',
            'password2'
        ]


class PostForm(forms.ModelForm):
    class Meta:
        model = Post
        fields = [
            'title',
            'category',
            'content',
            'image'
        ]


class CommentForm(forms.ModelForm):
    class Meta:
        model = Comment
        fields = ['comment']