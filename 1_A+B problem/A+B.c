#include<stdio.h>
#include<stdlib.h>

int a[201],b[201];

int cmpabs(int*a,int*b,int len){
    int i=len;
    int result=0;
    //result = 1,|a|>|b|
    //result = 0,|a|=|b|
    //result = -1,|a|<|b|
    while (i>=0)
    {
        if(a[i]>b[i])
        {
            result=1;
            break;
        }
        else if (a[i]<b[i])
        {
            result=-1;
            break;
        }
        
        i--;
    }
    return result;
}

int main(){
    int tmp[201];
    int res[201];
    int signa=0,signb=0;//1代表负数
    char c;
    int lena=0,lenb=0;
    int res_sign=0;
    
    //initial
    for (int i = 0; i < 201; i++)
    {
        a[0]=0;
        b[0]=0;
        res[0]=0;
    }
    
    //read in
    //A
    while ((c=getchar())!='\n' && c!=EOF)
    {
        if (c=='-')
        {
            signa=1;
        }
        else if (c>='0' && c<='9')
        {
            tmp[lena++]=c-'0';
        }
    }
    for (int i = 0; i < lena; i++)
    {
        a[i]=tmp[lena-i-1];
    }
    
    //B
    while ((c=getchar())!='\n' && c!=EOF)
    {
        if (c=='-')
        {
            signb=1;
        }
        else if (c>='0' && c<='9')
        {
            tmp[lenb++]=c-'0';
        }
        
    }
    for (int i = 0; i < lenb; i++)
    {
        b[i]=tmp[lenb-i-1];
    }

    //calculate
    //正+正 or 负+负
    if (signa==signb)
    {
        if (signa==0 && signb==0)
        {
            res_sign=0;
        }
        else
            res_sign=1;
        
        int cin=0;//进位信号
        for (int i = 0; i < 201; i++)
        {
            res[i]=(a[i]+b[i]+cin) % 10;
            cin=(a[i]+b[i]+cin) / 10;
        }
        
    }
    //正+负
    else
    {
        int flag=cmpabs(a,b,201);
        if (flag==0)
        {
            printf("0");
            return 0;
        }
        else if(flag==1)//|a|>|b|
        {
            if (signa==0 && signb==1)
            {
                res_sign=0;
            }
            else
                res_sign=1;
            
            for (int i = 0; i < 201; i++)
            {
                res[i]=a[i]-b[i];
            }

            int tmp=0;
            for (int i = 0; i < 201; i++)
            {
                res[i]+=tmp;
                if (res[i]<0)
                {
                    res[i]=(res[i]+10);
                    tmp=-1;
                }
                else
                {
                    tmp=0;
                }
                
            }
            
            
        }
        else if(flag==-1)//|a|<|b|
        {
            if (signa==1 && signb==0)
            {
                res_sign=0;
            }
            else
                res_sign=1;
            
            for (int i = 0; i < 201; i++)
            {
                res[i]=b[i]-a[i];
            }

            int tmp=0;
            for (int i = 0; i < 201; i++)
            {
                res[i]+=tmp;
                if (res[i]<0)
                {
                    res[i]=(res[i]+10);
                    tmp=-1;
                }
                else
                {
                    tmp=0;
                }
                
            }
        }
        
    }

    //print out
    if (res_sign==1)
    {
        printf("-");
    }
    
    int j=200;
    while (j>=0 && res[j]==0)
    {
        j--;
    }
    //all zero
    if (j==-1)
    {
        printf("0");
    }
    
    while (j>=0)
    {
        printf("%d",res[j]);
        j--;
    }
    
    getchar();
    return 0;
    
}