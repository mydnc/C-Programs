#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(){
	//inputs
	long double t1_a1,t1_a2,t1_b1,t1_b2,t1_c1,t1_c2;
	long double t1_ab,t1_ac,t1_bc,sum_t1;
	long double slope1_ab,slope1_ac,slope1_bc;
	long double t2_a1,t2_a2,t2_b1,t2_b2,t2_c1,t2_c2;
	long double t2_ab,t2_ac,t2_bc,sum_t2;
	long double slope2_ab,slope2_ac,slope2_bc;
	long double min;
	int ty;
	char a,nl=0;
    
	//input validations
	printf("Triangle #1:\n");
	if((ty = scanf(" %c [ %Lf ; %Lf ] , [ %Lf ; %Lf ] , [ %Lf ; %Lf ] }%c",&a,&t1_a1,&t1_a2,&t1_b1,&t1_b2,&t1_c1,&t1_c2,&nl))==8){
	
		//slopes of first triange
		slope1_ab = (t1_a2-t1_b2) / (t1_a1-t1_b1);
		slope1_ab = floor(10000*slope1_ab)/10000;
		slope1_ac = (t1_a2-t1_c2) / (t1_a1-t1_c1);
		slope1_ac = floor(10000*slope1_ac)/10000;
		slope1_bc = (t1_b2-t1_c2) / (t1_b1-t1_c1);
		slope1_bc = floor(10000*slope1_bc)/10000;
		
		//calculate distance of vertices of first triangle
		t1_ab = fabs(sqrt(((t1_a1-t1_b1)*(t1_a1-t1_b1))+((t1_a2-t1_b2)*(t1_a2-t1_b2))));
		t1_ac = fabs(sqrt(((t1_a1-t1_c1)*(t1_a1-t1_c1))+((t1_a2-t1_c2)*(t1_a2-t1_c2))));
		t1_bc = fabs(sqrt(((t1_b1-t1_c1)*(t1_b1-t1_c1))+((t1_b2-t1_c2)*(t1_b2-t1_c2))));
		
	
		if (slope1_ab == slope1_ac && slope1_bc == slope1_ac){
		  printf("Invalid triangle.\n");
		  return 0;
		}
  	}
	else if((ty = scanf(" %Lf , %Lf , %Lf }%c",&t1_ab,&t1_ac,&t1_bc,&nl))==4){
		
  	}

  	else{
    	printf("Invalid input.\n" );
    	return 0;
  	}
  	if(a != '{'){
		printf("Invalid input.\n" );
		return 0;
	}
	
	if((t1_ab > t1_ac+t1_bc && fabs(t1_ab-(t1_ac+t1_bc)) > 1e-12) ||
		fabs(t1_ab-fabs(t1_bc-t1_ac)) < 1e-12  ||
		(t1_ab<fabs(t1_bc-t1_ac) && fabs(t1_ab-t1_ac) > 1e-12) ||
		(t1_ac > t1_ab+t1_bc && fabs(t1_ac-(t1_ab+t1_bc)) > 1e-12) ||
		(t1_ac < fabs(t1_ab-t1_bc) && fabs(t1_ac-fabs(t1_ab-t1_bc)) > 1e-12) ||
    	fabs(t1_ac-fabs(t1_ab-t1_bc)) < 1e-12  ||
    	(t1_bc > t1_ab+t1_ac && fabs(t1_bc-(t1_ab+t1_ac)) > 1e-12) ||
    	(t1_bc < fabs(t1_ac-t1_ab) && fabs(t1_bc-fabs(t1_ac-t1_ab)) > 1e-12) ||
    	fabs(t1_bc-fabs(t1_ac-t1_ab)) < 1e-12 ){
		printf("Invalid triangle.\n");
		return 0;
  	}
	printf("Triangle #2:\n");
	
  	if((ty = scanf(" %c [ %Lf ; %Lf ] , [ %Lf ; %Lf ] , [ %Lf ; %Lf ] }%c",&a,&t2_a1,&t2_a2,&t2_b1,&t2_b2,&t2_c1,&t2_c2,&nl))==8){
    	//slopes of second triange
		slope2_ab = (t2_a2-t2_b2) / (t2_a1-t2_b1);
		slope2_ab = floor(10000*slope2_ab)/10000;
		slope2_ac = (t2_a2-t2_c2) / (t2_a1-t2_c1);
		slope2_ac = floor(10000*slope2_ac)/10000;
		slope2_bc = (t2_b2-t2_c2) / (t2_b1-t2_c1);
		slope2_bc = floor(10000*slope2_bc)/10000;
		
		//calculate distance of vertices of second triangle
		t2_ab = fabs(sqrt(((t2_a1-t2_b1)*(t2_a1-t2_b1))+((t2_a2-t2_b2)*(t2_a2-t2_b2))));
		t2_ac = fabs(sqrt(((t2_a1-t2_c1)*(t2_a1-t2_c1))+((t2_a2-t2_c2)*(t2_a2-t2_c2))));
		t2_bc = fabs(sqrt(((t2_b1-t2_c1)*(t2_b1-t2_c1))+((t2_b2-t2_c2)*(t2_b2-t2_c2))));

    	if (slope2_ab==slope2_ac && slope2_ac==slope2_bc){
      		printf("Invalid triangle.\n");
      		return 0;
    	}
  	}
	
	else if((ty = scanf(" %Lf , %Lf , %Lf }%c",&t2_ab,&t2_ac,&t2_bc,&nl))==4){
	}

 	else{
		printf("Invalid input.\n" );
		return 0;
	}
	if(a != '{'){
		printf("Invalid input.\n" );
		return 0;
	}
		
	if((t2_ab > t2_ac+t2_bc && fabs(t2_ab-(t2_ac+t2_bc)) > 1e-12) ||
		fabs(t2_ab-fabs(t2_bc-t2_ac)) < 1e-12  ||
		(t2_ab<fabs(t2_bc-t2_ac) && fabs(t2_ab-t2_ac) > 1e-12) ||
		(t2_ac > t2_ab+t2_bc && fabs(t2_ac-(t2_ab+t2_bc)) > 1e-12) ||
		(t2_ac < fabs(t2_ab-t2_bc) && fabs(t2_ac-fabs(t2_ab-t2_bc)) > 1e-12) ||
    	fabs(t2_ac-fabs(t2_ab-t2_bc)) < 1e-12  ||
    	(t2_bc > t2_ab+t2_ac && fabs(t2_bc-(t2_ab+t2_ac)) > 1e-12) ||
    	(t2_bc < fabs(t2_ac-t2_ab) && fabs(t2_bc-fabs(t2_ac-t2_ab)) > 1e-12) ||
    	fabs(t2_bc-fabs(t2_ac-t2_ab)) < 1e-12){
		printf("Invalid triangle.\n");
		return 0;
  	}
	
	if(fabs(slope2_ab) == fabs(slope2_ac) && fabs(slope2_ab) == fabs(slope2_bc)){
		printf("The points do not form a triangle.\n");
		return 0;
	}

	//sums of first triange's sides
	sum_t1 = (double)t1_ab+t1_ac+t1_bc;
	
	
	//sums of second triange's sides
	sum_t2 = (double)t2_ab+t2_ac+t2_bc;

	//min
	min = (sum_t1 < sum_t2) ? sum_t1 : sum_t2;
	
	//compare
	if(fabs(sum_t1-sum_t2) <= 1e-12*min){
		if(((t1_ab==t2_ab)&&(t1_ac==t2_ac)&&(t1_bc==t2_bc))||((t1_ab==t2_ac)&&(t1_ac==t2_bc)&&(t1_bc==t2_ab))||((t1_ab==t2_bc)&&(t1_ac==t2_ab)&&(t1_bc==t2_ac))){
			printf("The triangles are identical.\n");
			return 0;
		}
		else{
			printf("The triangles are not identical, however, they have the same circumference.\n");
			return 0;
		}
	}
	else{
		if(fabs(sum_t1) > fabs(sum_t2)){
			printf("Triangle #1 has a longer circumference.\n");
			return 0;
		}
		else{
			printf("Triangle #2 has a longer circumference.\n");
			return 0;
		}
	}
	return 0;
}