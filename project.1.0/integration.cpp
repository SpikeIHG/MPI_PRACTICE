#include<iostream>
#include<mpi.h>
using namespace std;

double func(double x)
{
    return x;
}


double trap(double leftend,double rightend,int trap_count,double base_len)
{
    double estimate{0.0},x{0};
    int i{0};

    estimate=(leftend+rightend)/2.0;
    for(i=1;i<trap_count;++i)
    {
        x=leftend+base_len*i;
        estimate+=func(x);
    }
    estimate=estimate*base_len;

    return estimate;
}

int main(void)
{
    double lhs=0.0,rhs=10.0;
    //cout<<"Please enter the left end and right end of the function(b shall larger than a)\n";
    //if(!(cin>>lhs>>rhs)||lhs>rhs)
      //  exit(EXIT_FAILURE);
    int slicenum=1<<10;
    double a{0.0},b{0.0},h{0.0},local_a{0.0},local_b{0.0};
    int my_rank{0},comm_sz{0},local_slicenum{0},source{0};
    double local_inte{0.0},total_inte{0.0};

    MPI_Init(nullptr,nullptr);
    MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&comm_sz);

    a=lhs,b=rhs;
    h=(b-a)/slicenum;
    local_slicenum=slicenum/comm_sz;
    local_a=a+my_rank*h;
    local_b=local_a+h*local_slicenum;
    local_inte=trap(local_a,local_b,local_slicenum,h);
    
    if(my_rank!=0)
    {
        MPI_Send(&local_inte,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD);
    }
    else{
        total_inte=local_inte;
        for(source=1;source<comm_sz;++source)
        {
            MPI_Recv(&local_inte,1,MPI_DOUBLE,source,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            total_inte+=local_inte;
        }
    }

    if(my_rank==0)
    {
        printf("With n= %d trapezoids, our estimate \n"
        "of the integral from %lf to %lf = %.15e\n",slicenum,a,b,total_inte);
    }

    MPI_Finalize();
    return 0;
}