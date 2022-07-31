## `nqueens`
![](pics\nqueens.png)

Scanner sc = new Scanner(System.in);
int M = sc.nextInt();
int N = sc.nextInt();
int sum=0;
int counter = M;
while(counter <= N){
if(counter%2 == 1){
    sum += counter;
}
counter++;
}        
System.out.print(sum);