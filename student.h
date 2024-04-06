#ifndef _STUDENT_H_
#define _STUDENT_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>

    #define ANSI_COLOR_RED     "\x1b[31m"
    #define ANSI_COLOR_GREEN   "\x1b[32m"
    #define ANSI_COLOR_RESET   "\x1b[0m"

    typedef struct Student{
        char Gender;
        int id;
        int acadimec_year;
        float GPA;
        char Fname[50];
        char Lname[50];
        struct Student *priv_student;
        struct Student *next_student;
    }student;
    
    student *head = NULL;
    
    void add_student(student **list, student data);
    void remove_student(student **list, int location);
    void display_all_students(student *list);
    void display_student(student *list, int location);
    void sort_list (student **list); //according to the ID.
    int search_student(student **list, int id); //returns student location in the list.
    void update_student(student **list, student new_data, int location, int select_to_update);
    int check_name(char name[50]);
    int check_duplicate_id(student *head, int id);
    int check_list(student *list);

#endif