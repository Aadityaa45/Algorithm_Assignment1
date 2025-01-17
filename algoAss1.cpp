/*The function sortEmp takes the vector/array/list of “empid” of integers as an input along with the vector/array/list  “salary” containing the corresponding integer's weights. The system needs to sort the employee details (“empid”) starting from the starting index to the end based on the fact that employee_id with a higher salary appears first. In the case of equal salary put the greater empid in first in the list.

Test case:

Empid = {1,3,8,5,8}

Salary = {100,800,400,800,700}

Expected Output:{5,3,8,8,1}*/

#include<iostream>
#include<algorithm>
using namespace std;


void ArraySettingAsitIs(int dup_emp_id[],int dup_emp_sal[],int n,int emp_id[], int emp_sal_id[]){
    for(int i=0;i<n;i++){
        emp_id[i]=dup_emp_id[i];
        emp_sal_id[i]=dup_emp_sal[i];
    }
}

void CountingSort(int emp_id[], int emp_salary[], int n) {
    int comparisions = 0, loop_iterates = 0;

    // Step 1: Find the maximum salary
    int max_salary = *max_element(emp_salary, emp_salary + n);

    // Step 2: Create a counting array
    int count[max_salary + 1] = {0};

    // Step 3: Count the frequency of each salary
    for (int i = 0; i < n; i++) {
        count[emp_salary[i]]++;
        loop_iterates++;
    }

    // Step 4: Create arrays for the sorted results
    int sorted_emp_id[n];
    int sorted_emp_salary[n];
    int index = 0;

    // Step 5: Traverse the count array in descending order
    for (int salary = max_salary; salary >= 0; salary--) {
        while (count[salary] > 0) {
            for (int i = 0; i < n; i++) {
                comparisions++;
                if (emp_salary[i] == salary) {
                    sorted_emp_id[index] = emp_id[i];
                    sorted_emp_salary[index] = emp_salary[i];
                    index++;
                    count[salary]--;
                    break; // Move to the next occurrence
                }
            }
        }
    }

    // Step 6: Copy sorted results back to the original arrays
    for (int i = 0; i < n; i++) {
        emp_id[i] = sorted_emp_id[i];
        emp_salary[i] = sorted_emp_salary[i];
    }

    /*cout << "\nSORTED ARRAY USING COUNTING SORT:\n";
    for(int k=0;k<n;k++){
        cout<<"\nEMPLOYEE ID:"<<emp_id[k]<<" || "<<"EMPLOYEE SALARY:"<<emp_salary[k]<<endl;
    }
    cout << "\nITERATIONS: " << iterations;
    cout << "\nCOMPARISIONS: " << comparisions << endl;*/

    cout << "\nSORTED ARRAY USING COUNTING SORT:\n";
    cout<<"*****************************************"<<endl;
    for(int k=0;k<n;k++){
        cout<<"\nEMPLOYEE ID:"<<emp_id[k]<<" || "<<"EMPLOYEE SALARY:"<<emp_salary[k]<<endl;
    }
    cout<<"*****************************************"<<endl;
    cout<<"\n````````````````````COMPARISIONS ANALYSIS OF COUNTING SORT``````````````````````"<<endl;
    cout<<"\nLOOP ITERATES: "<<loop_iterates;
    cout<<"\nCOMPARISION DONE:"<<comparisions;
    cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
}

void NormalBUbbleSort(int emp_id[],int emp_sal[],int n){
    int loop_iterates=0;
    int comparisions=0;


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (emp_sal[j] < emp_sal[j + 1] ||
                (emp_sal[j] == emp_sal[j + 1] && emp_id[j] < emp_id[j + 1])) {
                // Swap salaries
                int temp_salary = emp_sal[j];
                emp_sal[j] = emp_sal[j + 1];
                emp_sal[j + 1] = temp_salary;
                // Swap employee IDs
                int temp_id = emp_id[j];
                emp_id[j] = emp_id[j + 1];
                emp_id[j + 1] = temp_id;
                comparisions++;
            }
        }
        loop_iterates++;
    }

    cout << "\nSORTED ARRAY USING NORMAL BUBBLE SORT:\n";
    cout<<"*****************************************"<<endl;
    for(int k=0;k<n;k++){
        cout<<"\nEMPLOYEE ID:"<<emp_id[k]<<" || "<<"EMPLOYEE SALARY:"<<emp_sal[k]<<endl;
    }
    cout<<"*****************************************"<<endl;
    cout<<"\n````````````````````COMPARISIONS ANALYSIS OF NORMAL BUBBLE SORT``````````````````````"<<endl;
    cout<<"\nLOOP ITERATES: "<<loop_iterates;
    cout<<"\nCOMPARISION DONE:"<<comparisions;
    cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
}

void ShellSort(int emp_id[], int emp_salary[], int n) {
    int comparisions = 0, loop_iterates = 0;

    for (int gap = n / 2; gap >= 1; gap /= 2) {
        for (int j = gap; j < n; j++) {
            for (int i = (j - gap); i >= 0; i -= gap) {
                loop_iterates++;
                comparisions++;
                if (emp_salary[i + gap] > emp_salary[i] ||
                    (emp_salary[i + gap] == emp_salary[i] && emp_id[i + gap] > emp_id[i])) {
                    // Swap salaries
                    int temp1 = emp_salary[i + gap];
                    emp_salary[i + gap] = emp_salary[i];
                    emp_salary[i] = temp1;

                    // Swap employee IDs
                    int temp2 = emp_id[i + gap];
                    emp_id[i + gap] = emp_id[i];
                    emp_id[i] = temp2;
                } else {
                    break;
                }
            }
        }
    }

    /*cout << "\nSORTED ARRAY USING SHELL SORT SORT:\n";
    for(int k=0;k<n;k++){
        cout<<"\nEMPLOYEE ID:"<<emp_id[k]<<" || "<<"EMPLOYEE SALARY:"<<emp_salary[k]<<endl;
    }
    cout << "\nITERATIONS: " << iterations;
    cout << "\nCOMPARISIONS: " << comparisions << endl;*/

    cout << "\nSORTED ARRAY USING SHELL SORT:\n";
    cout<<"*****************************************"<<endl;
    for(int k=0;k<n;k++){
        cout<<"\nEMPLOYEE ID:"<<emp_id[k]<<" || "<<"EMPLOYEE SALARY:"<<emp_salary[k]<<endl;
    }
    cout<<"*****************************************"<<endl;
    cout<<"\n````````````````````COMPARISIONS ANALYSIS OF SHELL SORT``````````````````````"<<endl;
    cout<<"\nLOOP ITERATES: "<<loop_iterates;
    cout<<"\nCOMPARISION DONE:"<<comparisions;
    cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
}

void OptimizedBubbleSort(int emp_id[],int emp_salary[],int n){
    int loop_iterates=0;
    bool swap = false;
    int comparisions=0;


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            swap = false;
            if (emp_salary[j] < emp_salary[j + 1] ||
                (emp_salary[j] == emp_salary[j + 1] && emp_id[j] < emp_id[j + 1])) {
                // Swap salaries
                int temp_salary = emp_salary[j];
                emp_salary[j] = emp_salary[j + 1];
                emp_salary[j + 1] = temp_salary;
                // Swap employee IDs
                int temp_id = emp_id[j];
                emp_id[j] = emp_id[j + 1];
                emp_id[j + 1] = temp_id;
                swap=true;
                comparisions++;
            }
        }
        loop_iterates++;
        if(swap==false){
            break;
        }
        
    }

    /*cout<<"SORTED ARRAY IS:";
    for(int k=0;k<n;k++){
        cout<<"\nEMPLOYEE ID:"<<emp_id[k]<<" || "<<"EMPLOYEE SALARY:"<<emp_salary[k]<<endl;
    }

    cout<<"\nLOOP ITERATES: "<<loop_iterates;
    cout<<"\nCOMPARISION DONE:"<<comparisions;*/

    cout << "\nSORTED ARRAY USING OPTIMIZED BUBBLE SORT:\n";
    cout<<"*****************************************"<<endl;
    for(int k=0;k<n;k++){
        cout<<"\nEMPLOYEE ID:"<<emp_id[k]<<" || "<<"EMPLOYEE SALARY:"<<emp_salary[k]<<endl;
    }
    cout<<"*****************************************"<<endl;
    cout<<"\n````````````````````COMPARISIONS ANALYSIS OF OPTIMIZED BUBBLE SORT``````````````````````"<<endl;
    cout<<"\nLOOP ITERATES: "<<loop_iterates;
    cout<<"\nCOMPARISION DONE:"<<comparisions;
    cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    
}

void InsertionSort(int emp_id[],int emp_salary[],int n){
    int comparision_count =0;
    int iterate_count = 0;
    for(int i=1;i<n;i++){
        int temp1=emp_salary[i];
        int temp2 = emp_id[i];
        int j=i-1;
        while(j>=0 && (emp_salary[j] < temp1 || (emp_salary[j] == temp1 && emp_id[j] < temp2))){
            emp_salary[j+1]=emp_salary[j];
            emp_id[j+1]=emp_id[j];
            j=j-1;
            comparision_count=comparision_count+1;
        }
        iterate_count=iterate_count+1;
        emp_salary[j+1]=temp1;
        emp_id[j+1]=temp2;
    }
    cout << "\nSORTED ARRAY USING INSERTION SORT:\n";
    cout<<"*****************************************"<<endl;
    for(int k=0;k<n;k++){
        cout<<"\nEMPLOYEE ID:"<<emp_id[k]<<" || "<<"EMPLOYEE SALARY:"<<emp_salary[k]<<endl;
    }
    cout<<"*****************************************"<<endl;
    cout<<"\n````````````````````COMPARISIONS ANALYSIS OF INSERTION SORT``````````````````````"<<endl;
    cout<<"\nLOOP ITERATES: "<<iterate_count;
    cout<<"\nCOMPARISION DONE:"<<comparision_count;
    cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
}

int main() {
    
    int n;

    cout<<"\t\tENTER THE NUMBER OF EMPLOYESS:";
    cin>>n;

    int emp_id[n]={};
    int emp_salary[n]={};

    for(int i=0;i<n;i++){
        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"\nENTER THE EMPLOYEE ID OF EMPLOYEE " <<i+1<<":";
        cin>>emp_id[i];
        
        cout<<"ENTER THE SALARY OF EMPLOYEE "<<emp_id[i]<<":";
        cin>>emp_salary[i];

        while (emp_salary[i] <= 0) {
            cout << "Salary cannot be zero or negative. Re-enter: ";
            cin >> emp_salary[i];
        }
    }
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\n\nEntered EMPLOYEE ID and SALARY"<<endl;
    cout<<"---------------------------------------"<<endl;
    for(int j=0;j<n;j++){
        cout<<"\nEMPLOYEE ID:"<<emp_id[j]<<" | "<<"SALARY:"<<emp_salary[j]<<endl;
    }
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    int duplicate_E_ID[n]={};
    int duplicate_E_SAL[n]={};

    for(int i=0;i<n;i++){
        duplicate_E_ID[i]=emp_id[i];
        duplicate_E_SAL[i]=emp_salary[i];
    }

    InsertionSort(emp_id,emp_salary,n);
    cout<<"\n\n+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*"<<endl;
    ArraySettingAsitIs(duplicate_E_ID,duplicate_E_SAL,n,emp_id,emp_salary);
    NormalBUbbleSort(emp_id,emp_salary,n);
    cout<<"\n\n+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*"<<endl;
    ArraySettingAsitIs(duplicate_E_ID,duplicate_E_SAL,n,emp_id,emp_salary);
    OptimizedBubbleSort(emp_id,emp_salary,n);
    cout<<"\n\n+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*"<<endl;
    ArraySettingAsitIs(duplicate_E_ID,duplicate_E_SAL,n,emp_id,emp_salary);
    ShellSort(emp_id,emp_salary,n);
    cout<<"\n\n+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*+-%*"<<endl;
    ArraySettingAsitIs(duplicate_E_ID,duplicate_E_SAL,n,emp_id,emp_salary);
    CountingSort(emp_id,emp_salary,n);
    return 0;
}


