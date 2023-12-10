# Package-tracking-system

This C program simulates a simple package tracking system. Users can add, display, update package information, and exit the system.

## Features

- **Add Package:**
  - Users can add a new package by providing tracking number, current location, estimated arrival time, and destination address.

- **Display Packages:**
  - Users can display information for a specific package by entering its tracking number or display all packages.

- **Update Package:**
  - Users can update the current location, estimated arrival time, and destination address for a specific package.

- **Exit:**
  - Users can exit the package tracking system.

## How to Compile and Run

1. Open a terminal window.
2. Navigate to the project directory.

```bash
gcc -o PackageTrackingSystem main.c
./PackageTrackingSystem
```

## Package Actions

- **Add:**
  - Enter `add` to add a new package. Follow the prompts to provide package details.

- **Display:**
  - Enter `display` to display package information. Enter the tracking number or type `all` to display all packages.

- **Update:**
  - Enter `update` to update package information. Enter the tracking number and provide new details.

- **Exit:**
  - Enter `exit` to exit the package tracking system.

## Example Usage

1. Add a new package:
   ```
   Enter action (add, display, update, exit): add
   Enter tracking number: ABC123
   Enter current location: Warehouse A
   Enter estimated arrival time: 2023-12-31
   Enter destination address: Customer's Home
   Package added successfully.
   ```

2. Display all packages:
   ```
   Enter action (add, display, update, exit): display
   Enter tracking number to display (or type 'all' to display all packages): all
   Tracking Number: ABC123
   Current Location: Warehouse A
   Estimated Arrival Time: 2023-12-31
   Destination Address: Customer's Home
   ```

3. Update a package:
   ```
   Enter action (add, display, update, exit): update
   Enter tracking number to update: ABC123
   Enter new current location for tracking number ABC123: In Transit
   Enter new estimated arrival time for tracking number ABC123: 2023-12-25
   Enter new destination address for tracking number ABC123: Final Destination
   Information updated successfully.
   ```

4. Exit the system:
   ```
   Enter action (add, display, update, exit): exit
   ```
