from django.contrib import admin
from .models import Student, Course


@admin.register(Student)
class StudentAdmin(admin.ModelAdmin):
    list_display = (
        'id',
        'name',
        'email',
        'phone',
        'age',
        'created_at',
    )

    search_fields = (
        'name',
        'email',
    )

    list_filter = (
        'age',
        'created_at',
    )


@admin.register(Course)
class CourseAdmin(admin.ModelAdmin):
    list_display = (
        'id',
        'course_name',
        'course_code',
        'duration',
    )

    search_fields = (
        'course_name',
        'course_code',
    )