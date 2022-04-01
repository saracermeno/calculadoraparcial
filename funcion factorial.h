float factorial(float num1){
    float factorial, i;
    if (num1 < 0){
        factorial = 0;
    }
    else if (num1 == 0){
        factorial = 1;
    }
    else{
        factorial = 1;
        for (i = 1; i <= num1; i++){
            factorial *= i;
        }
    }
    return factorial;
}