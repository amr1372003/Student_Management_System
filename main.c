#include "student.h"
// T ID is 1372003

int main(){
    printf(ANSI_COLOR_RESET);
    student new_student;
    char type_of_user;
    int id, choice, run = 1, number_of_students = 0, index = 0, select_update = 0;
    int while1 = 0, while2 = 0;

    while (run != 7){
start: 
        system("cls");
        printf("enter S for student or T for teacher : ");
        scanf(" %c", &type_of_user);
        system("cls");
        if (type_of_user == 'S' || type_of_user == 's'){
            printf("enter your S ID : ");
            scanf("%d", &id);
            if (id < 1000000 || id > 9999999){
                printf(ANSI_COLOR_RED);
                printf("invaled ID.\n");
                printf(ANSI_COLOR_RESET);
                printf("1) back.\n");
                printf("enter your choice : ");
                scanf(" %d", &run);
                if (run == 1){
                    goto start;
                }
            }else if(search_student(&head, id) == 0){
                printf(ANSI_COLOR_RED);
                printf("ID was not found : \n");
                printf(ANSI_COLOR_RESET);
                printf("1) back.\n");
                printf("enter your choice : ");
                scanf(" %d", &run);
                if (run == 1){
                    goto start;
                }
            }
            else{
                while(while1 != 10){
start1:
                    system("cls");
                    printf("choose function : \n1) display data.\n2) back.\n");
                    printf("enter your choice ");
                    scanf("%d", &choice);
                    if (choice == 1){
                        index = search_student(&head, id);
                        display_student(head, index);
                        printf("1) back.\n");
                        printf("enter your choice : ");
                        scanf(" %d", &run);
                        if (run == 1){
                            goto start1;
                        }
                    }
                    
                    else if (choice == 2){
                        while1 = 10;
                    }
                }
            }
        }
        else if (type_of_user == 'T' || type_of_user == 't'){
            printf("enter your T ID : ");
            scanf("%d", &id);
            if (id != 1372003){
                printf(ANSI_COLOR_RED);
                printf("invaled ID.\n");
                printf(ANSI_COLOR_RESET);
                printf("1) back.\n");
                printf("enter your choice : ");
                scanf(" %d", &run);
                if (run == 1){
                    goto start;
                }
            }
            while(while2 != 6){
start2:
                system("cls");
                printf("choose function : \n1) add student.\n2) remove student.\n3) retrieve student data.\n4) update student.\n5) display all students.\n6) back.\n");
                printf("enter your choice : ");
                scanf("%d", &choice);
                if (choice == 1){
                    system("cls");
                    printf("enter the number of student you want to add : ");
                    scanf("%d", &number_of_students);
                    for (int i = 1; i <= number_of_students; i++){
                        system("cls");
                        printf("enter your %d student id : ", i);
                        scanf("%d", &id);
                        if (id < 1000000 || id > 9999999){
                            printf(ANSI_COLOR_RED);
                            printf("invaled ID.\n");
                            printf(ANSI_COLOR_RESET);
                            printf("1) back.\n");
                            printf("enter your choice : ");
                            scanf(" %d", &run);
                            if (run == 1){
                                goto start2;
                            }
                        }
                        if(check_duplicate_id(head, id) == 0){
                            new_student.id = id;
                        }else{
                            printf(ANSI_COLOR_RED);
                            printf("ID is already exist.\n");
                            printf(ANSI_COLOR_RESET);
                            printf("1) back.\n");
                            printf("enter your choice : ");
                            scanf(" %d", &run);
                            if (run == 1){
                                goto start2;
                            }
                        }
                        
                        printf("enter your %d student first name : ", i);
                        scanf("%s", new_student.Fname); 
                        if(check_name (new_student.Fname) == 1){
                            printf(ANSI_COLOR_RED);
                            printf("invaled name.\n");
                            printf(ANSI_COLOR_RESET);
                            printf("1) back.\n");
                            printf("enter your choice : ");
                            scanf(" %d", &run);
                            if (run == 1){
                                goto start2;
                            }
                        }  
                        printf("enter your %d student last name : ", i);
                        scanf("%s", new_student.Lname);
                        if(check_name (new_student.Lname) == 1){
                            printf(ANSI_COLOR_RED);
                            printf("invaled name.\n");
                            printf(ANSI_COLOR_RESET);
                            printf("1) back.\n");
                            printf("enter your choice : ");
                            scanf(" %d", &run);
                            if (run == 1){
                                goto start2;
                            }
                        }  
                        printf("enter your %d student Gender : ", i);
                        scanf(" %s", &new_student.Gender);
                        if ((new_student.Gender != 'M') && (new_student.Gender != 'm') && (new_student.Gender != 'F') && (new_student.Gender != 'f')){
                            printf(ANSI_COLOR_RED);
                            printf("invaled gender.\n");
                            printf(ANSI_COLOR_RESET);
                            printf("1) back.\n");
                            printf("enter your choice : ");
                            scanf(" %d", &run);
                            if (run == 1){
                                goto start2;
                            }
                        }
                        printf("enter your %d student academic year : ", i);
                        scanf("%d", &new_student.acadimec_year);
                        if (new_student.acadimec_year < 1 || new_student.acadimec_year > 5){
                            printf(ANSI_COLOR_RED);
                            printf("invaled academic year.\n");
                            printf(ANSI_COLOR_RESET);
                            printf("1) back.\n");
                            printf("enter your choice : ");
                            scanf(" %d", &run);
                            if (run == 1){
                                goto start2;
                            }
                        }
                        printf("enter your %d student GPA : ", i);
                        scanf("%f", &new_student.GPA);
                        if (new_student.GPA > 4.0 || new_student.GPA < 0.0){
                            printf(ANSI_COLOR_RED);
                            printf("invaled GPA.\n");
                            printf(ANSI_COLOR_RESET);
                            printf("1) back.\n");
                            printf("enter your choice : ");
                            scanf(" %d", &run);
                            if (run == 1){
                                goto start2;
                            }
                        }
                        add_student(&head, new_student);
                    }
                    sort_list(&head);
                    system("cls");
                    printf(ANSI_COLOR_GREEN);
                    printf("student added.\n");
                    printf(ANSI_COLOR_RESET);
                    printf("1) back.\n");
                    printf("enter your choice : ");
                    scanf(" %d", &run);
                    if (run == 1){
                        goto start2;
                    }
                }
            
                else if (choice == 2){
                    system("cls");
                    if (check_list(head) == 0){
                        printf(ANSI_COLOR_RED);
                        printf("the list is empty.\n");
                        printf(ANSI_COLOR_RESET);
                        printf("1) back.\n");
                        printf("enter your choice : ");
                        scanf(" %d", &run);
                        if (run == 1){
                            goto start2;
                        }
                    }
                    else{
                        printf("enter the number of student you want to remove : ");
                        scanf("%d", &number_of_students);
                        for (int i = 1; i <= number_of_students; i++){
                            printf("enter the %d ID of the student : ", i);
                            scanf("%d", &id);
                            if (id < 1000000 || id > 9999999){
                                printf(ANSI_COLOR_RED);
                                printf("invaled ID.\n");
                                printf(ANSI_COLOR_RESET);
                                printf("1) back.\n");
                                printf("enter your choice : ");
                                scanf(" %d", &run);
                                if (run == 1){
                                    goto start2;
                                }
                            }else{
                                index = search_student(&head, id);
                                if (index == 0){
                                    printf(ANSI_COLOR_RED);
                                    printf("ID not found.\n");
                                    printf(ANSI_COLOR_RESET);
                                    printf("1) back.\n");
                                    printf("enter your choice : ");
                                    scanf(" %d", &run);
                                    if (run == 1){
                                        goto start2;
                                    }
                                }else{
                                    remove_student(&head, index);
                                }
                            }
                        }
                        system("cls");
                        printf(ANSI_COLOR_GREEN);
                        printf("student removed.\n");
                        printf(ANSI_COLOR_RESET);
                        printf("1) back.\n");
                        printf("enter your choice : ");
                        scanf(" %d", &run);
                        if (run == 1){
                            goto start2;
                        }
                    }
                }
                
                else if (choice == 3){
                    system("cls");
                    if (check_list(head) == 0){
                        printf(ANSI_COLOR_RED);
                        printf("the list is empty.\n");
                        printf(ANSI_COLOR_RESET);
                        printf("1) back.\n");
                        printf("enter your choice : ");
                        scanf(" %d", &run);
                        if (run == 1){
                            goto start2;
                        }
                    }else{
                        printf("enter the ID of the student you want to retieve his data : ");
                        scanf("%d", &id);
                        if (id < 1000000 || id > 9999999){
                            printf(ANSI_COLOR_RED);
                            printf("invaled ID.\n");
                            printf(ANSI_COLOR_RESET);
                            printf("1) back.\n");
                            printf("enter your choice : ");
                            scanf(" %d", &run);
                            if (run == 1){
                                goto start2;
                            }
                        }else{
                            index = search_student(&head, id);
                            if (index == 0){
                                printf(ANSI_COLOR_RED);
                                printf("ID not found.\n");
                                printf(ANSI_COLOR_RESET);
                                printf("1) back.\n");
                                printf("enter your choice : ");
                                scanf(" %d", &run);
                                if (run == 1){
                                    goto start2;
                                }
                            }else{
                                display_student(head, index);
                                printf("1) back.\n");
                                printf("enter your choice : ");
                                scanf(" %d", &run);
                                if (run == 1){
                                    goto start2;
                                }
                            }
                        }
                    }
                    
                }
                
                else if (choice == 4){
                    system("cls");
                    if (check_list(head) == 0){
                        printf(ANSI_COLOR_RED);
                        printf("the list is empty.\n");
                        printf(ANSI_COLOR_RESET);
                        printf("1) back.\n");
                        printf("enter your choice : ");
                        scanf(" %d", &run);
                        if (run == 1){
                            goto start2;
                        }
                    }else{
                    printf("enter your student id : ");
                    scanf("%d", &id);
                    if (id < 1000000 || id > 9999999){
                        printf(ANSI_COLOR_RED);
                        printf("invaled ID.\n");
                        printf(ANSI_COLOR_RESET);
                        printf("1) back.\n");
                        printf("enter your choice : ");
                        scanf(" %d", &run);
                        if (run == 1){
                            goto start2;
                        }
                    }
                    index = search_student(&head,id);
                    if (index == 0){
                        printf(ANSI_COLOR_RED);
                        printf("student does not exist.\n");
                        printf(ANSI_COLOR_RESET);
                        printf("1) back.\n");
                        printf("enter your choice : ");
                        scanf(" %d", &run);
                        if (run == 1){
                            goto start2;
                        }
                    }else{
                            printf("enter 1 to update acatemic year or 2 to update GPA : ");
                            scanf("%d", &select_update);
                            if (select_update == 1){
                                printf("enter the updated acatemic year : ");
                                scanf("%d", &new_student.acadimec_year);
                                if (new_student.acadimec_year < 1 || new_student.acadimec_year > 5){
                                    printf(ANSI_COLOR_RED);
                                    printf("invaled academic year.\n");
                                    printf(ANSI_COLOR_RESET);
                                    printf("1) back.\n");
                                    printf("enter your choice : ");
                                    scanf(" %d", &run);
                                    if (run == 1){
                                        goto start2;
                                    }
                                }
                            }else if(select_update == 2){
                                printf("enter the updated GPA : ");
                                scanf("%f", &new_student.GPA);
                                if (new_student.GPA > 4.0 || new_student.GPA < 0.0){
                                    printf(ANSI_COLOR_RED);
                                    printf("invaled GPA.\n");
                                    printf(ANSI_COLOR_RESET);
                                    printf("1) back.\n");
                                    printf("enter your choice : ");
                                    scanf(" %d", &run);
                                    if (run == 1){
                                        goto start2;
                                    }
                                } 
                            }else{
                                update_student(&head, new_student, index, select_update);
                                system("cls");
                                printf(ANSI_COLOR_GREEN);
                                printf("updated.\n");
                                printf(ANSI_COLOR_RESET);
                                printf("1) back.\n");
                                printf("enter your choice : ");
                                scanf(" %d", &run);
                                if (run == 1){
                                    goto start2;
                                }
                            }
                        }
                    }
                }
                
                else if (choice == 5){
                    system("cls");
                    display_all_students(head);
                    printf("1) back.\n");
                    printf("enter your choice : ");
                    scanf(" %d", &run);
                    if (run == 1){
                        goto start2;
                    } 
                }
                
                else if(choice == 6){
                    system("cls");
                    while2 = 6;
                }
                
                else{
                    system("cls");
                    printf(ANSI_COLOR_RED);
                    printf("invaled choice.\n");
                    printf(ANSI_COLOR_RESET);
                }
            }
        }
        else{
            system("cls");
            printf(ANSI_COLOR_RED);
            printf("invaled.\n");
            printf(ANSI_COLOR_RESET);
            printf("1) back.\n");
            printf("enter your choice : ");
            scanf(" %d", &run);
            if (run == 1){
                goto start;
            } 
        }
        while1 = 0;
        while2 = 0;
        system("cls");
        printf("enter 7 to exite, any other number to continue : ");
        scanf(" %d", &run);
    }
}


void add_student(student **list, student data){
    system("cls");
    student *temp = NULL;
    temp =(student *)malloc(sizeof(student));
    if (temp != NULL){
        temp -> id = data.id;
        temp -> Gender = data.Gender;
        temp -> GPA = data.GPA;
        temp -> acadimec_year = data.acadimec_year;
        for (int i = 0; i < 50; i++){
            temp -> Fname[i] = data.Fname[i];
            temp -> Lname[i] = data.Lname[i]; 
        }
        if (*list == NULL){
            temp -> priv_student = NULL;
            temp -> next_student = NULL;
            (*list) = temp;
        }else{
            temp -> next_student = (*list);
            temp -> priv_student = NULL;
            (*list) -> priv_student = temp;
            (*list) = temp;
        }
    }else{
        printf(ANSI_COLOR_RED);
        printf("memory err, canot add student.");
        printf(ANSI_COLOR_RESET);
    }
}

void remove_student(student **list, int location){
    system("cls");
    if (*list == NULL){
        printf(ANSI_COLOR_RED);
        printf("list is empty\n");
        printf(ANSI_COLOR_RESET);
    }else{
    
    if (location == 1){
        student *temp = *list;
        *list = (*list)->next_student;
        if (*list != NULL) {
            (*list)->priv_student = NULL;
        }
        free(temp);
    }
    else{
            student *this_student = NULL;
            student *privous_student = NULL;
            int student_pos = location;
            this_student = *list;
            while (student_pos > 1){
                this_student = this_student -> next_student;
                student_pos--;
            }
            if (this_student -> next_student == NULL){
                privous_student = this_student -> priv_student;
                privous_student -> next_student = NULL;
                free(this_student);
                this_student = NULL;
            }
            else{
                privous_student = this_student -> priv_student;
                privous_student -> next_student = this_student -> next_student;
                this_student -> next_student -> priv_student = privous_student;
                free(this_student);
                this_student = NULL;
            }
        }
    }
}

void display_all_students(student *list){
    system("cls");
    student *temp = list;
    if (list == NULL){
        printf(ANSI_COLOR_RED);
        printf("list is empty\n");
        printf(ANSI_COLOR_RESET);
    }else{
        printf("students : \n");
        printf("first name \t last name \t ID \t\t Gender \t acadimec year \t GPA \n");
        printf("%s \t\t %s \t %d \t %c \t\t %d \t\t %f \t\t \n", temp -> Fname, temp -> Lname, temp -> id, toupper(temp -> Gender), temp -> acadimec_year, temp -> GPA );
        while (temp -> next_student != NULL){
            temp = temp -> next_student;
            printf("%s \t\t %s \t %d \t %c \t\t %d \t\t %f \t\t \n", temp -> Fname, temp -> Lname, temp -> id, toupper(temp -> Gender), temp -> acadimec_year, temp -> GPA );
        }
        printf("\n");
    }
}

void display_student(student *list, int location){
    system("cls");
    int student_pos = location;
    student *this_student = NULL;
    this_student = list;
    if (list == NULL){
        printf(ANSI_COLOR_RED);
        printf("list is empty\n");
        printf(ANSI_COLOR_RESET);
    }else{
        while (student_pos > 1){
                this_student = this_student -> next_student;
                student_pos--;
        }
        printf("first name \t last name \t ID \t\t Gender \t acadimec year \t GPA \n");
        printf("%s \t\t %s \t %d \t %c \t\t %d \t\t %f \t\t \n", this_student -> Fname, this_student -> Lname, this_student -> id, toupper(this_student -> Gender), this_student -> acadimec_year, this_student -> GPA );
    }
}

void sort_list (student **list){
    if (*list == NULL){
        printf(ANSI_COLOR_RED);
        printf("list is empty\n");
        printf(ANSI_COLOR_RESET);
    }else{
        student *current = NULL;
        student *index = NULL;
        student temp;
        current = *list;
        while (current != NULL) {
            index = current -> next_student;
            while (index != NULL) {
                if (current -> id > index -> id) {
                    temp.id = current -> id;
                    for (int i = 0; i < 50; i++){
                        temp.Fname[i] = current -> Fname[i];
                        temp.Lname[i] = current -> Lname[i];
                    }
                    temp.Gender = current -> Gender;
                    temp.GPA = current -> GPA;
                    temp.acadimec_year = current -> acadimec_year;

                    current -> id = index -> id;
                    for (int i = 0; i < 50; i++){
                        current -> Fname[i] = index -> Fname[i];
                        current -> Lname[i] = index -> Lname[i];
                    }
                    current -> Gender = index -> Gender;
                    current -> GPA = index -> GPA;
                    current -> acadimec_year = index -> acadimec_year;
                    
                    index -> id = temp.id;
                    for (int i = 0; i < 50; i++){
                        index -> Fname[i] = temp.Fname[i];
                        index -> Lname[i] = temp.Lname[i];
                    }
                    index -> Gender = temp.Gender;
                    index -> GPA = temp.GPA;
                    index -> acadimec_year = temp.acadimec_year;
                }
                index = index -> next_student;
            }
            current = current -> next_student;
        }
    }
}

int search_student(student **list, int id){
    if (*list == NULL){
        printf(ANSI_COLOR_RED);
        printf("list is empty\n");
        printf(ANSI_COLOR_RESET);
        return 0;
    }else{
        student *this_student = NULL;
        this_student = (*list);
        int location = 1;
        while (this_student){
            if (this_student -> id == id){
                return location;
            }
            location++;
            this_student = this_student -> next_student;
        }
        return 0; // not found
    }
}

void update_student(student **list, student new_data, int location, int select_to_update){
    if (*list == NULL){
        printf(ANSI_COLOR_RED);
        printf("list is empty\n");
        printf(ANSI_COLOR_RESET);
    }else{
        student *temp = NULL;
        temp = (*list);
        int student_pos = location - 1;
        while (temp && student_pos){
            student_pos--;
            temp = temp -> next_student;
        }
        if(temp){
            if (select_to_update == 1){
                temp -> acadimec_year = new_data.acadimec_year;
            }else if (select_to_update == 2){
                temp -> GPA = new_data.GPA;
            }
        }else{
            printf("invaled location, %i", location+1);
        }
    }
}

int check_name (char name[50]){
    for (int i = 0; name[i] != '\0'; i++){
        if (!isalpha(name[i])){
            return 1; //found
        }
    }
}

int check_duplicate_id(student *list, int id) {
    student *current = NULL;
    current = list;
    while (current != NULL) {
        if (current -> id == id) {
            return 1; //Duplicate found
        }
        current = current -> next_student;
    }
    return 0; //No duplicate
}

int check_list(student *list){
    if (list == NULL){
        return 0;
    }else{
        return 1;
    }
}
