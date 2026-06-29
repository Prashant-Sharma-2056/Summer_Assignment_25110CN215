// WAP to Create inventory management system.
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    int quantity;
    double price;
    int reorder_level; // Minimum quantity before warning triggers
};

struct Item inventory[MAX_ITEMS];
int item_count = 0;


// 1. Function to introduce a new stock profile
void addItem() {
    if (item_count >= MAX_ITEMS) {
        printf("\nError: Inventory database capacity full!\n");
        return;
    }

    struct Item itm;
    printf("\nEnter Product ID: ");
    scanf("%d", &itm.id);

    // Unique ID tracking boundaries
    for (int i = 0; i < item_count; i++) {
        if (inventory[i].id == itm.id) {
            printf("Error: Product ID %d already exists!\n", itm.id);
            return;
        }
    }

    printf("Enter Product Name (No spaces): ");
    scanf("%s", itm.name);
    
    printf("Enter Initial Quantity: ");
    scanf("%d", &itm.quantity);
    
    printf("Enter Unit Price ($): ");
    scanf("%lf", &itm.price);
    
    printf("Enter Reorder Alert Level Quantity: ");
    scanf("%d", &itm.reorder_level);

    // Commit ledger configuration block to master storage array
    inventory[item_count] = itm;
    item_count++;
    printf("\nProduct successfully registered to inventory!\n");
}

// 2. Function to adjust stock levels (Restock or Sale dispatch)
void updateStock() {
    if (item_count == 0) {
        printf("\nDatabase is empty. No items registered.\n");
        return;
    }

    int target_id, update_type, delta_qty;
    printf("\nEnter Product ID to update: ");
    scanf("%d", &target_id);

    for (int i = 0; i < item_count; i++) {
        if (inventory[i].id == target_id) {
            printf("\nProduct Found: %s | Current Stock: %d\n", inventory[i].name, inventory[i].quantity);
            printf("1. Restock (Add Quantity)\n");
            printf("2. Dispatch (Deduct Quantity)\n");
            printf("Select operation (1-2): ");
            scanf("%d", &update_type);

            if (update_type != 1 && update_type != 2) {
                printf("Invalid selection. Transaction aborted.\n");
                return;
            }

            printf("Enter quantity amount change: ");
            scanf("%d", &delta_qty);

            if (delta_qty <= 0) {
                printf("Error: Quantity adjustment must be greater than zero.\n");
                return;
            }

            if (update_type == 1) {
                inventory[i].quantity += delta_qty;
                printf("\nSuccess: Restocked! New quantity: %d\n", inventory[i].quantity);
            } else {
                if (delta_qty > inventory[i].quantity) {
                    printf("\nTransaction Aborted: Insufficient stock! Only %d units available.\n", inventory[i].quantity);
                } else {
                    inventory[i].quantity -= delta_qty;
                    printf("\nSuccess: Dispatched! Remaining quantity: %d\n", inventory[i].quantity);
                }
            }
            return;
        }
    }
    printf("Error: Product ID %d not found.\n", target_id);
}

// 3. Function to pull warnings on item shortages
void checkReorderAlerts() {
    if (item_count == 0) {
        printf("\nDatabase empty. No inventory items exist.\n");
        return;
    }

    int flag = 0;
    printf("\n--- CRITICAL STOCK ALERTS (REORDER REQUIRED) ---\n");
    printf("%-10s %-25s %-15s %-15s\n", "ID", "Name", "Current Qty", "Min Level");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < item_count; i++) {
        if (inventory[i].quantity <= inventory[i].reorder_level) {
            printf("%-10d %-25s %-15d %-15d\n", 
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].reorder_level);
            flag = 1;
        }
    }

    if (!flag) {
        printf("[All clear: Every asset meets safe warehouse limits]\n");
    }
    printf("------------------------------------------------------------\n");
}

// 4. Function to generate a clean inventory balance sheet 
void displayInventory() {
    if (item_count == 0) {
        printf("\nInventory ledger empty. No items to log.\n");
        return;
    }

    double total_inventory_value = 0;

    printf("\n--------------------------------------------------------------------------------\n");
    printf("%-10s %-25s %-12s %-12s %-15s\n", "ID", "Product Name", "Quantity", "Price", "Total Value");
    printf("--------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < item_count; i++) {
        double current_val = inventory[i].quantity * inventory[i].price;
        total_inventory_value += current_val;

        printf("%-10d %-25s %-12d $%-11.2f $%-14.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price, current_val);
    }
    
    printf("--------------------------------------------------------------------------------\n");
    printf("Total Active SKUs Logged: %-3d | Total Warehouse Valuation: $%.2f\n", item_count, total_inventory_value);
    printf("--------------------------------------------------------------------------------\n");
}


int main() {
    int choice;

    while (1) {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Product\n");
        printf("2. Update Stock Quantity\n");
        printf("3. View Reorder Alert Flags\n");
        printf("4. Generate Inventory Report\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addItem(); break;
            case 2: updateStock(); break;
            case 3: checkReorderAlerts(); break;
            case 4: displayInventory(); break;
            case 5: printf("\nClosing Inventory System. Goodbye!\n"); return 0;
            default: printf("Invalid choice! Select an option between 1 and 5.\n");
        }
    }
    return 0;
}
