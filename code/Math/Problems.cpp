// Function to calculate the number of digits in N! in base B
ll NoOfDigitInNFactInBaseB(ll N,ll B){
  ll i;
  double ans=0;
  for(i=1;i<=N;i++)ans+=log(i);
  ans=ans/log(B),ans=ans+1;
  return(ll)ans;
}
// Precompute SOD and NOD for all numbers up to N
ll sod[N], nod[N];
void buildSOD(){ // O(N log N)
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            sod[j] += i;
        }
    }
}
void buildNOD(){ // O(N log N)
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            nod[j]++;
        }
    }
}
// NOD(n) = number of divisors = MUL(e+1)
// SOD(n) = sum of divisors = MUL((p^(e+1)-1)/(p-1))
// Single query: O(log n) using SPF