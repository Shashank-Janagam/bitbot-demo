#include <stdio.h>

float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

void bmi() {
    float weight, height;
    
    // Input weight and height
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);
    
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    
    // Calculate BMI
    float bmi = calculateBMI(weight, height);
    
    // Display the result
    printf("Your BMI is: %.2f\n", bmi);
    
    // Interpret the BMI value
    printf("Interpretation:\n");
    if (bmi < 18.5) {
        printf("Underweight\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("Normal weight\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("Overweight\n");
    } else {
        printf("Obesity\n");
    }
    
    // return 0;
}