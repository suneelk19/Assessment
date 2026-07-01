# from django.urls import path
# from . import views

# urlpatterns = [

#     path('', views.home, name='home'),

#     path(
#         'post/<int:pk>/',
#         views.post_detail,
#         name='post_detail'
#     ),

#     path(
#         'create/',
#         views.create_post,
#         name='create_post'
#     ),

#     path(
#         'edit/<int:pk>/',
#         views.edit_post,
#         name='edit_post'
#     ),

#     path(
#         'delete/<int:pk>/',
#         views.delete_post,
#         name='delete_post'
#     ),

#     path(
#         'like/<int:pk>/',
#         views.like_post,
#         name='like_post'
#     ),

#     path(
#         'follow/<int:user_id>/',
#         views.follow_author,
#         name='follow_author'
#     ),

#     path(
#         'comment/<int:pk>/',
#         views.add_comment,
#         name='add_comment'
#     ),
# ]


from django.urls import path
from . import views

from django.contrib import admin
from django.urls import path, include

from django.conf import settings
from django.conf.urls.static import static

urlpatterns = [

    path(
        'admin/',
        admin.site.urls
    ),

    path(
        '',
        include('blog.urls')
    ),

    path(
        'accounts/',
        include('django.contrib.auth.urls')
    ),
]

if settings.DEBUG:
    urlpatterns += static(
        settings.MEDIA_URL,
        document_root=settings.MEDIA_ROOT
    )

urlpatterns = [

    path('', views.home, name='home'),

    path(
        'post/<int:pk>/',
        views.post_detail,
        name='post_detail'
    ),

    path(
        'create/',
        views.create_post,
        name='create_post'
    ),

    path(
        'edit/<int:pk>/',
        views.edit_post,
        name='edit_post'
    ),

    path(
        'delete/<int:pk>/',
        views.delete_post,
        name='delete_post'
    ),

    path(
        'like/<int:pk>/',
        views.like_post,
        name='like_post'
    ),

    path(
        'follow/<int:user_id>/',
        views.follow_author,
        name='follow_author'
    ),

    path(
        'comment/<int:pk>/',
        views.add_comment,
        name='add_comment'
    ),

    path(
        'comment/edit/<int:pk>/',
        views.edit_comment,
        name='edit_comment'
    ),

    path(
        'comment/delete/<int:pk>/',
        views.delete_comment,
        name='delete_comment'
    ),
    
    path(
    'register/',
    views.register,
    name='register'
),
    
    path(
    'login/',
    views.user_login, 
    name='login'
    ),
    
path(
    'logout/', 
    views.user_logout, 
    name='logout'
    ),

path(
    '', 
    views.home, 
    name='home'
    ),
]