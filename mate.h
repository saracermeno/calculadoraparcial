int f(int x){
	
	if(x<0){
		return 0;
	}else if(x>1){
		return x*f(x-1);
	}
}

float s(float a,float b){
	return a+b;
}
float r(float a, float b){
	return a-b;
}
float d(float a, float b){
	return a/b;
}
float m(float a, float b){
	return a*b;
}
