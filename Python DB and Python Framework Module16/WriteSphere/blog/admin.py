# from django.contrib import admin
# from .models import Category, Post, Comment, Like, Follow


# @admin.register(Category)
# class CategoryAdmin(admin.ModelAdmin):
#     list_display = ('id', 'name')
#     search_fields = ('name',)


# @admin.register(Post)
# class PostAdmin(admin.ModelAdmin):
#     list_display = (
#         'id',
#         'title',
#         'author',
#         'category',
#         'created_at'
#     )

#     list_filter = (
#         'category',
#         'created_at'
#     )

#     search_fields = (
#         'title',
#         'content'
#     )


# @admin.register(Comment)
# class CommentAdmin(admin.ModelAdmin):
#     list_display = (
#         'id',
#         'user',
#         'post',
#         'created_at'
#     )

#     search_fields = (
#         'user__username',
#         'comment'
#     )


# @admin.register(Like)
# class LikeAdmin(admin.ModelAdmin):
#     list_display = (
#         'id',
#         'user',
#         'post'
#     )


# @admin.register(Follow)
# class FollowAdmin(admin.ModelAdmin):
#     list_display = (
#         'id',
#         'follower',
#         'following'
#     )



# second code

# from django.contrib import admin
# from .models import Category, Post, Comment, Like, Follow
# from .models import *

# @admin.register(Category)
# class CategoryAdmin(admin.ModelAdmin):
#     list_display = ('id', 'name')
#     search_fields = ('name',)


# @admin.register(Post)
# class PostAdmin(admin.ModelAdmin):
#     list_display = (
#         'id',
#         'title',
#         'author',
#         'category',
#         'created_at'
#     )

#     list_filter = (
#         'category',
#         'created_at'
#     )

#     search_fields = (
#         'title',
#         'content'
#     )


# @admin.register(Comment)
# class CommentAdmin(admin.ModelAdmin):
#     list_display = (
#         'id',
#         'user',
#         'post',
#         'created_at'
#     )

#     search_fields = (
#         'user__username',
#         'comment'
#     )


# @admin.register(Like)
# class LikeAdmin(admin.ModelAdmin):
#     list_display = (
#         'id',
#         'user',
#         'post'
#     )


# @admin.register(Follow)
# class FollowAdmin(admin.ModelAdmin):
#     list_display = (
#         'id',
#         'follower',
#         'following'
#     )




# third code

from django.contrib import admin
from .models import Post, Category, Comment, Like, Follow


@admin.register(Post)
class PostAdmin(admin.ModelAdmin):

    list_display = (
        'title',
        'author',
        'category',
        'created_at'
    )

    search_fields = (
        'title',
        'author__username'
    )

    list_filter = (
        'category',
        'created_at'
    )


admin.site.register(Category)
admin.site.register(Comment)
admin.site.register(Like)
admin.site.register(Follow)