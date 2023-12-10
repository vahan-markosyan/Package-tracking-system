#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKAGES 100

// Define a structure for your package
typedef struct {
    char trackingNumber[20];
    char currentLocation[50];
    char estimatedArrivalTime[20];
    char destinationAddress[50];
} Package;

// Function to add a package to the array
void addPackage(Package packages[], int* numPackages, char* trackingNumber, char* currentLocation, char* estimatedArrivalTime, char* destinationAddress) {
    if (*numPackages < MAX_PACKAGES) {
        // Create a new package
        Package newPackage;
        strcpy(newPackage.trackingNumber, trackingNumber);
        strcpy(newPackage.currentLocation, currentLocation);
        strcpy(newPackage.estimatedArrivalTime, estimatedArrivalTime);
        strcpy(newPackage.destinationAddress, destinationAddress);

        // Add the new package to the array
        packages[*numPackages] = newPackage;
        (*numPackages)++;
        printf("Package added successfully.\n");
    }
    else {
        printf("Cannot add more packages. Maximum limit reached.\n");
    }
}

// Function to display a specific package by tracking number
void displayPackage(Package packages[], int numPackages, char* trackingNumber) {
    for (int i = 0; i < numPackages; i++) {
        if (strcmp(packages[i].trackingNumber, trackingNumber) == 0) {
            // Package found, display its information
            printf("Tracking Number: %s\n", packages[i].trackingNumber);
            printf("Current Location: %s\n", packages[i].currentLocation);
            printf("Estimated Arrival Time: %s\n", packages[i].estimatedArrivalTime);
            printf("Destination Address: %s\n", packages[i].destinationAddress);
            return;
        }
    }

    // If the loop completes, the package was not found
    printf("Package with tracking number %s not found.\n", trackingNumber);
}

// Function to update package information
void updatePackage(Package packages[], int numPackages, char* trackingNumber) {
    for (int i = 0; i < numPackages; i++) {
        if (strcmp(packages[i].trackingNumber, trackingNumber) == 0) {
            // Package found, prompt user for update information
            printf("Enter new current location for tracking number %s: ", trackingNumber);
            scanf("%s", packages[i].currentLocation);
            printf("Enter new estimated arrival time for tracking number %s: ", trackingNumber);
            scanf("%s", packages[i].estimatedArrivalTime);
            printf("Enter new destination address for tracking number %s: ", trackingNumber);
            scanf("%s", packages[i].destinationAddress);
            printf("Information updated successfully.\n");
            return;
        }
    }

    // If the loop completes, the package was not found
    printf("Package with tracking number %s not found.\n", trackingNumber);
}

// Function to display all packages in the array
void displayPackages(Package packages[], int numPackages) {
    char trackingNumber[20];

    printf("Enter tracking number to display (or type 'all' to display all packages): ");
    scanf("%s", trackingNumber);

    if (strcmp(trackingNumber, "all") == 0) {
        // Display all packages
        for (int i = 0; i < numPackages; i++) {
            printf("Tracking Number: %s\n", packages[i].trackingNumber);
            printf("Current Location: %s\n", packages[i].currentLocation);
            printf("Estimated Arrival Time: %s\n", packages[i].estimatedArrivalTime);
            printf("Destination Address: %s\n", packages[i].destinationAddress);
            printf("\n");
        }
    }
    else {
        // Display a specific package
        displayPackage(packages, numPackages, trackingNumber);
    }
}

int main() {
    Package packages[MAX_PACKAGES];
    int numPackages = 0;
    char trackingNumber[20];
    char currentLocation[50];
    char estimatedArrivalTime[20];
    char destinationAddress[50];
    char action[10];

    // Main loop
    while (1) {
        printf("Enter action (add, display, update, exit): ");
        scanf("%s", action);
        if (strcmp(action, "add") == 0) {
            printf("Enter tracking number: ");
            scanf("%s", trackingNumber);
            printf("Enter current location: ");
            scanf("%s", currentLocation);
            printf("Enter estimated arrival time: ");
            scanf("%s", estimatedArrivalTime);
            printf("Enter destination address: ");
            scanf("%s", destinationAddress);
            addPackage(packages, &numPackages, trackingNumber, currentLocation, estimatedArrivalTime, destinationAddress);
        }
        else if (strcmp(action, "display") == 0) {
            displayPackages(packages, numPackages);
        }
        else if (strcmp(action, "update") == 0) {
            printf("Enter tracking number to update: ");
            scanf("%s", trackingNumber);
            updatePackage(packages, numPackages, trackingNumber);
        }
        else if (strcmp(action, "exit") == 0) {
            break;  // Exit the loop
        }
        else {
            printf("Invalid action. Please try again.\n");
        }
    }

    return 0;
}