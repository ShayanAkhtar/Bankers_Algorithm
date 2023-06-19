    #include<iostream>
    using namespace std;


    ///////Function to calculate Allocated Resources/////////////////////
    int* sum_of_columns(int** arr,int rows,int columns)
    {
        int* sum = new int[columns];
        for(int i=0;i<columns;i++)
        {
            sum[i]=0;
            for(int j=0;j<rows;j++)
            {
                sum[i]+=arr[j][i];
            }
        }
        return sum;//pip install pymongo
    }
    //Function to check if the process is safe//////////////////////////
    bool is_safe(int** remaining_required_resources,int* available_resources,int process,int no_of_resources)
    {
        bool is_safe=true;
        for(int i=0;i<no_of_resources;i++)
        {
            if(remaining_required_resources[process][i]>available_resources[i])
            {
                is_safe=false;
                break;
            }
        }
        return is_safe;
    }
    ////////////////////////////////////MAIN/////////////////////////////////////
    int main()
    {
        int no_of_resources,no_of_processes;
        cout<<"Enter the number of Resources: ";
        cin>>no_of_resources;

        int* total_resources = new int[no_of_resources];
        for(int i=0;i<no_of_resources;i++)
        {
            cout<<"Enter the total number of resources for R"<<i+1<<": ";
            cin>>total_resources[i];
        }

    //////////////////////////////////////////////////////////
        system("cls");
        cout<<"Enter the number of Processes: ";
        cin>>no_of_processes;

        cout<<"Enter the allocated resources for each process: \n";
    ////////////DYNAMIC MEMORY ALLOCATION////////////////////
        int** allocated_resources = new int*[no_of_processes];
        for (int i = 0; i < no_of_processes; i++)
        {
            allocated_resources[i] = new int[no_of_resources];
        }
        
        for (int i = 0; i < no_of_processes; i++)
        {
            for (int j = 0; j < no_of_resources; j++)
            {
                cout<<"Enter the number of resources allocated to P"<<i+1<<" for R"<<j+1<<": ";
                cin>>allocated_resources[i][j];
            }
        }

    //////////////////////////////////////////////////////////
        system("cls");
        cout<<"Enter the maximum required resources for each process: \n";
    ////////////DYNAMIC MEMORY ALLOCATION////////////////////
        int** max_required_resources = new int*[no_of_processes];
        for (int i = 0; i < no_of_processes; i++)
        {
            max_required_resources[i] = new int[no_of_resources];
        }

        for (int i = 0; i < no_of_processes; i++)
        {
            for (int j = 0; j < no_of_resources; j++)
            {
                cout<<"Enter the maximum number of resources required by P"<<i+1<<" for R"<<j+1<<": ";
                cin>>max_required_resources[i][j];
            }

        }
        system("cls");
    //////////////////////////////////////////////////////////

        int* total_allocated_resources = new int[no_of_resources];
        total_allocated_resources = sum_of_columns(allocated_resources,no_of_processes,no_of_resources);

        int* available_resources = new int[no_of_resources];
        for(int i=0;i<no_of_resources;i++)
        {
            available_resources[i]=total_resources[i]-total_allocated_resources[i];
        }

    //////////////////////////////////////////////////////////

        int** remaining_required_resources = new int*[no_of_processes];
        for (int i = 0; i < no_of_processes; i++)
        {
            remaining_required_resources[i] = new int[no_of_resources];
        }
        
        for(int i=0;i<no_of_processes;i++)
        {
            for(int j=0;j<no_of_resources;j++)
            {
                remaining_required_resources[i][j]=max_required_resources[i][j]-allocated_resources[i][j];
            }
        }
        
    //////////////////////////////////////////////////////////

        int* safe_sequence = new int[no_of_processes];
        int status = 0;
        bool cmp=true;
        bool check;

        while(cmp)
        {
            cmp=false; 
            for(int i=0;i<no_of_processes;i++)
            {
                check=false;
                for(int j=0;j<status;j++)
                {
                    if(i+1==safe_sequence[j])
                    {
                        check=true;
                        break;
                    }
                }
                if(!check)
                {
                    if(is_safe(remaining_required_resources,available_resources,i,no_of_resources))
                    {
                        cmp=true;
                        safe_sequence[status]=i+1 ;
                        status++;
                        for(int j=0;j<no_of_resources;j++)
                        {
                            available_resources[j]+=allocated_resources[i][j];
                        }
                    }
                }
            }
        }
    //////////////////////////////////////////////////////////
        if(status>1)
        {
            cout<<"The safe Sequence: ";
            for(int i=0;i<status;i++)
            {
                cout<<"P"<<safe_sequence[i]<<" → ";
            }
        }
        

        if(status==no_of_processes)
        {cout<<"\nSafe State";}
        else
        {cout<<"\nUnsafe State";} 

        return 0;
    }