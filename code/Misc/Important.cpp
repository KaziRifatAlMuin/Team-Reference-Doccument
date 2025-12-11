// Ternary Search Template
double left = 0, right = 1e8;
// unimodal function: exactly one minima or maxima
while(fabs(right - left) > eps){
    double m1 = left + (right - left) / 3;
    double m2 = right - (right - left) / 3;
    double f1 = 0, f2 = 0;
    for(int i = 0; i < n; i++){
        f1 = max(f1, t[i] + fabs(x[i] - m1));
        f2 = max(f2, t[i] + fabs(x[i] - m2));
    } // ........min........
    if(f1 > f2) left = m1;
    else if(f1 < f2) right = m2;
    else left = m1, right = m2;
}