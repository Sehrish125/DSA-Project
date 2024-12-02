#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
struct User {
    string credential; 
    string password;
};

class UserAuth {
private:
    vector<User> userDatabase;

    
    bool isValidEmail(const string& email) {
        size_t atPos = email.find('@');
        size_t dotPos = email.find('.', atPos);
        return atPos != string::npos && dotPos != string::npos && dotPos > atPos;
    }

   
    bool isValidPhoneNumber(const string& phone) {
        if (phone.length() != 10) return false;
        for (char c : phone) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    bool isCredentialTaken(const string& credential) {
        for (const auto& user : userDatabase) {
            if (user.credential == credential) {
                return true;
            }
        }
        return false;
    }

public:
    
    void signUp() {
        string credential, password;
        cout << "Enter Email or Phone Number for Sign Up: ";
        cin >> credential;

        if (!isValidEmail(credential) && !isValidPhoneNumber(credential)) {
            cout << "Invalid email or phone number format. Try again.\n";
            return;
        }

        if (isCredentialTaken(credential)) {
            cout << "This email or phone number is already registered.\n";
            return;
        }

        cout << "Enter Password: ";
        cin >> password;

        userDatabase.push_back({credential, password});
        cout << "Sign-up successful! You can now log in.\n";
    }

    
    void login() {
        string credential, password;
        cout << "Enter Email or Phone Number to Log In: ";
        cin >> credential;

        for (const auto& user : userDatabase) {
            if (user.credential == credential) {
                cout << "Enter Password: ";
                cin >> password;
                if (user.password == password) {
    	cout << "              ***********************************************" << endl;
        cout << "              *                                             *" << endl;
                     cout <<"~~~~~~~~~~~~~~~Login successful!~~~~~~~~~~~~~~~~\n";
                    cout << "~~~Welcome to the Inventory Management System~~~\n";
        cout << "              *                                             *" << endl;
        cout << "              ***********************************************" << endl;
                
                
        
		}
				 else {
                    cout << "Incorrect password. Please try again.\n";
                }
                return;
            }
        }

        cout << "No account found with this email or phone number.\n";
    }
    
};
struct StockItem {
    int id;
    string name;
    int quantity;
    double price;
    StockItem* next;
};

// Class to manage the stock using a linked list
class StockManager {
private:
    StockItem* head;

public:
    StockManager() : head(nullptr) {}

    // Add a new stock item
    void addItem(int id, const string& name, int quantity, double price) {
        StockItem* newItem = new StockItem{id, name, quantity, price, nullptr};

        if (!head) {
            head = newItem;
        } else {
            StockItem* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newItem;
        }

        cout << "Item added successfully!\n";
    }

    // Display all stock items
    void displayItems() {
        if (!head) {
            cout << "No items in stock.\n";
            return;
        }

        StockItem* temp = head;
        cout << "\n--- Stock Items ---\n";
        while (temp) {
            cout << "ID: " << temp->id
                 << ", Name: " << temp->name
                 << ", Quantity: " << temp->quantity
                 << ", Price: $" << temp->price << "\n";
            temp = temp->next;
        }
    }

    // Update the quantity of a stock item
    void updateQuantity(int id, int newQuantity) {
        StockItem* temp = head;
        while (temp) {
            if (temp->id == id) {
                temp->quantity = newQuantity;
                cout << "Quantity updated successfully!\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Item with ID " << id << " not found.\n";
    }

    // Delete a stock item
    void deleteItem(int id) {
        if (!head) {
            cout << "No items in stock.\n";
            return;
        }

        if (head->id == id) {
            StockItem* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Item deleted successfully!\n";
            return;
        }

        StockItem* temp = head;
        while (temp->next && temp->next->id != id) {
            temp = temp->next;
        }

        if (temp->next) {
            StockItem* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Item deleted successfully!\n";
        } else {
            cout << "Item with ID " << id << " not found.\n";
        }
    }

    ~StockManager() {
        while (head) {
            StockItem* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
struct Product {
    int productID;
    string productName;
    int quantity;
    double price;
    Product* next;
    Product(int id, string name, int qty, double pr)
        : productID(id), productName(name), quantity(qty), price(pr), next(NULL) {}
};
class ProductList {
private:
    Product* head;

public:
    ProductList() : head(NULL) {}
    void addProduct(int id, string name, int qty, double price) {
        Product* newProduct = new Product(id, name, qty, price);
        if (!head) {
            head = newProduct;
        } else {
            Product* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newProduct;
        }
        cout << "Product added successfully.\n";
    }
    void updateProduct(int id, string newName, int newQty, double newPrice) {
        Product* temp = head;
        while (temp) {
            if (temp->productID == id) {
                temp->productName = newName;
                temp->quantity = newQty;
                temp->price = newPrice;
                cout << "Product updated successfully.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Product not found.\n";
    }
    void deleteProduct(int id) {
        if (!head) {
            cout << "List is empty. No products to delete.\n";
            return;
        }
        if (head->productID == id) {
            Product* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Product deleted successfully.\n";
            return;
        }
        Product* temp = head;
        while (temp->next && temp->next->productID != id) {
            temp = temp->next;
        }
        if (temp->next) {
            Product* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Product deleted successfully.\n";
        } else {
            cout << "Product not found.\n";
        }
    }
    void displayProducts() {
        if (!head) {
            cout << "No products available.\n";
            return;
        }
        Product* temp = head;
        while (temp) {
            cout << "Product ID: " << temp->productID << "\n";
            cout << "Product Name: " << temp->productName << "\n";
            cout << "Quantity: " << temp->quantity << "\n";
            cout << "Price: $" << temp->price << "\n";
            cout << "------------------------\n";
            temp = temp->next;
        }
    }
    ~ProductList() {
        while (head) {
            Product* toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }
};
struct Order {
    int orderId;
    string customerName;
    string orderDate;
    float totalAmount;
    Order* next;
};

class OrderManagement {
private:
    Order* head;

public:
    OrderManagement() {
        head = NULL; // Changed nullptr to NULL
    }

    void addOrder() {
        Order* newOrder = new Order();
        cout << "Enter order ID: ";
        cin >> newOrder->orderId;
        cout << "Enter customer name: ";
        cin.ignore(); // To clear the newline from the input buffer
        getline(cin, newOrder->customerName);
        cout << "Enter order date (YYYY-MM-DD): ";
        cin >> newOrder->orderDate;
        cout << "Enter total amount: ";
        cin >> newOrder->totalAmount;

        newOrder->next = NULL; // Changed nullptr to NULL

        if (head == NULL) { // Changed nullptr to NULL
            head = newOrder;
        } else {
            Order* temp = head;
            while (temp->next != NULL) { // Changed nullptr to NULL
                temp = temp->next;
            }
            temp->next = newOrder;
        }
        cout << "Order added successfully.\n";
    }

    void updateOrder() {
        if (head == NULL) { // Changed nullptr to NULL
            cout << "No orders available to update.\n";
            return;
        }
        int orderId;
        cout << "Enter the order ID to update: ";
        cin >> orderId;

        Order* temp = head;
        while (temp != NULL) { // Changed nullptr to NULL
            if (temp->orderId == orderId) {
                cout << "Enter new customer name: ";
                cin.ignore();
                getline(cin, temp->customerName);
                cout << "Enter new order date (YYYY-MM-DD): ";
                cin >> temp->orderDate;
                cout << "Enter new total amount: ";
                cin >> temp->totalAmount;
                cout << "Order updated successfully.\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Order not found.\n";
    }

    void deleteOrder() {
        if (head == NULL) { // Changed nullptr to NULL
            cout << "No orders available to delete.\n";
            return;
        }

        int orderId;
        cout << "Enter the order ID to delete: ";
        cin >> orderId;
        if (head->orderId == orderId) {
            Order* temp = head;
            head = head->next;
            delete temp;
            cout << "Order deleted successfully.\n";
            return;
        }
        Order* prev = head;
        Order* temp = head->next;
        while (temp != NULL) { // Changed nullptr to NULL
            if (temp->orderId == orderId) {
                prev->next = temp->next;
                delete temp;
                cout << "Order deleted successfully.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Order not found.\n";
    }

    void searchOrder() {
        if (head == NULL) { // Changed nullptr to NULL
            cout << "No orders available to search.\n";
            return;
        }

        int orderId;
        cout << "Enter the order ID to search: ";
        cin >> orderId;

        Order* temp = head;
        while (temp != NULL) { // Changed nullptr to NULL
            if (temp->orderId == orderId) {
                cout << "Order found:\n";
                cout << "Order ID: " << temp->orderId << endl;
                cout << "Customer Name: " << temp->customerName << endl;
                cout << "Order Date: " << temp->orderDate << endl;
                cout << "Total Amount: " << temp->totalAmount << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Order not found.\n";
    }

    void displayOrders() {
        if (head == NULL) { // Changed nullptr to NULL
            cout << "No orders available to display.\n";
            return;
        }

        Order* temp = head;
        cout << "Displaying all orders:\n";
        while (temp != NULL) { // Changed nullptr to NULL
            cout << "Order ID: " << temp->orderId << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Order Date: " << temp->orderDate << endl;
            cout << "Total Amount: " << temp->totalAmount << endl;
            cout << "-------------------------\n";
            temp = temp->next;
        }
    }
};



struct BillingItem {
    int id;
    string name;
    int quantity;
    double unitPrice;
    double totalPrice;
    BillingItem* next;
};

// Class to handle billing and payment
class BillingManager {
private:
    BillingItem* head;

    // Helper to calculate total price of an item
    double calculateTotalPrice(int quantity, double unitPrice) {
        return quantity * unitPrice;
    }

public:
    BillingManager() : head(nullptr) {}

    // Add an item to the bill
    void addItem(int id, const string& name, int quantity, double unitPrice) {
        double totalPrice = calculateTotalPrice(quantity, unitPrice);
        BillingItem* newItem = new BillingItem{id, name, quantity, unitPrice, totalPrice, nullptr};

        if (!head) {
            head = newItem;
        } else {
            BillingItem* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newItem;
        }

        cout << "Item added to bill successfully!\n";
    }

    // Display the bill
    void displayBill() {
        if (!head) {
            cout << "No items in the bill.\n";
            return;
        }

        double grandTotal = 0.0;
        BillingItem* temp = head;

        cout << "\n--- Bill Details ---\n";
        cout << left << setw(10) << "ID"
             << setw(20) << "Name"
             << setw(10) << "Qty"
             << setw(15) << "Unit Price"
             << setw(15) << "Total Price" << endl;
        cout << string(70, '-') << endl;

        while (temp) {
            cout << left << setw(10) << temp->id
                 << setw(20) << temp->name
                 << setw(10) << temp->quantity
                 << setw(15) << fixed << setprecision(2) << temp->unitPrice
                 << setw(15) << temp->totalPrice << endl;

            grandTotal += temp->totalPrice;
            temp = temp->next;
        }

        cout << string(70, '-') << endl;
        cout << right << setw(50) << "Grand Total: " << fixed << setprecision(2) << grandTotal << endl;
    }

    // Process payment
    void processPayment() {
        if (!head) {
            cout << "No items in the bill. Add items before processing payment.\n";
            return;
        }

        double grandTotal = 0.0;
        BillingItem* temp = head;

        while (temp) {
            grandTotal += temp->totalPrice;
            temp = temp->next;
        }

        cout << "\n--- Payment ---\n";
        cout << "Total Amount Due: $" << fixed << setprecision(2) << grandTotal << endl;

        double amountPaid;
        cout << "Enter Payment Amount: $";
        cin >> amountPaid;

        if (amountPaid < grandTotal) {
            cout << "Insufficient payment. Please pay the full amount.\n";
        } else {
            double change = amountPaid - grandTotal;
            cout << "Payment successful! Change: $" << fixed << setprecision(2) << change << endl;
        }
    }

    ~BillingManager() {
        while (head) {
            BillingItem* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    UserAuth authSystem;
    StockManager stockManager;
    ProductList productList;
    OrderManagement orderManagement;
    BillingManager billingManager;

    int mainChoice, subChoice;
    while (true) {
        cout << "\n--- Inventory Management System ---\n";
        cout << "1. Sign Up\n";
        cout << "2. Log In\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            authSystem.signUp();
            break;

        case 2:
               authSystem.login();

            while (true) {
                cout << "\n~~~~~~~~ Choose Your Relevant Category ~~~~~~~~\n";
                cout << "1. Stock Management\n";
                cout << "2. Product Management\n";
                cout << "3. Order Management\n";
                cout << "4. Billing and Payments\n";
                cout << "5. Back to Main Menu\n";
                cout << "0. Exit\n";
                cout << "Enter your choice: ";
                cin >> subChoice;

                if (subChoice == 0) {
                    cout << "Exiting...\n";
                    return 0;
                } else if (subChoice == 5) {
                    authSystem.login();
                }
                
                switch (subChoice) {
    case 1: { // Stock Management
        while (true) {
            cout << "\n--- Stock Management ---\n";
            cout << "1. Add Item\n";
            cout << "2. Display Items\n";
            cout << "3. Update Quantity\n";
            cout << "4. Delete Item\n";
            cout << "5. Back to Previous Menu\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 0) {
                cout << "Exiting...\n";
                return 0;
            } else if (subChoice == 5) {
                // Break out of the current loop and go back to the previous menu
                break;
            }

            int id, quantity;
            string name;
            double price;
            switch (subChoice) {
                case 1:
                    cout << "Enter Item ID: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Enter Item Name: ";
                    getline(cin, name);
                    cout << "Enter Quantity: ";
                    cin >> quantity;
                    cout << "Enter Price: ";
                    cin >> price;
                    stockManager.addItem(id, name, quantity, price);
                    break;
                case 2:
                    stockManager.displayItems();
                    break;
                case 3:
                    cout << "Enter Item ID to Update: ";
                    cin >> id;
                    cout << "Enter New Quantity: ";
                    cin >> quantity;
                    stockManager.updateQuantity(id, quantity);
                    break;
                case 4:
                    cout << "Enter Item ID to Delete: ";
                    cin >> id;
                    stockManager.deleteItem(id);
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        }
        break;
    }
    // Other cases for the main menu


                case 2: { // Product Management
                    while (true) {
                        cout << "\n--- Product Management ---\n";
                        cout << "1. Add Product\n";
                        cout << "2. Update Product\n";
                        cout << "3. Delete Product\n";
                        cout << "4. View Products\n";
                        cout << "5. Back to Previous Menu\n";
                        cout << "0. Exit\n";
                        cout << "Enter your choice: ";
                        cin >> subChoice;

                       if (subChoice == 0) {
                    cout << "Exiting...\n";
                    return 0;
                } else if (subChoice == 5) {
                	authSystem.login();
                    
                }

                        int id, qty;
                        string name;
                        double price;
                        switch (subChoice) {
                        case 1:
                            cout << "Enter Product ID: ";
                            cin >> id;
                            cin.ignore();
                            cout << "Enter Product Name: ";
                            getline(cin, name);
                            cout << "Enter Quantity: ";
                            cin >> qty;
                            cout << "Enter Price: ";
                            cin >> price;
                            productList.addProduct(id, name, qty, price);
                            break;
                        case 2:
                            cout << "Enter Product ID to Update: ";
                            cin >> id;
                            cin.ignore();
                            cout << "Enter New Product Name: ";
                            getline(cin, name);
                            cout << "Enter New Quantity: ";
                            cin >> qty;
                            cout << "Enter New Price: ";
                            cin >> price;
                            productList.updateProduct(id, name, qty, price);
                            break;
                        case 3:
                            cout << "Enter Product ID to Delete: ";
                            cin >> id;
                            productList.deleteProduct(id);
                            break;
                        case 4:
                            productList.displayProducts();
                            break;
                        default:
                            cout << "Invalid choice. Try again.\n";
                        }
                    }
                    break;
                }
                case 3: { // Order Management
                while (true) {
        cout << "\nOrder Management System\n";
        cout << "1. Add Order\n";
        cout << "2. Update Order\n";
        cout << "3. Delete Order\n";
        cout << "4. Search Order\n";
        cout << "5. Display All Orders\n";
        cout << "6. Back to Previous Menu\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> subChoice;
        if (subChoice == 0) {
                    cout << "Exiting...\n";
                    return 0;
                } else if (subChoice == 6) {
                	authSystem.login();
                    
                }

        switch (subChoice) {
        case 1:
            orderManagement.addOrder();
            break;
        case 2:
            orderManagement.updateOrder();
            break;
        case 3:
            orderManagement.deleteOrder();
            break;
        case 4:
            orderManagement.searchOrder();
            break;
        case 5:
            orderManagement.displayOrders();
            break;
        case 6:
            cout << "Exiting program. \n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
                 case 4: // Billing and Payments
                    while (true) {
                        cout << "\n--- Billing and Payment ---\n";
                        cout << "1. Add Item to Bill\n";
                        cout << "2. Display Bill\n";
                        cout << "3. Process Payment\n";
                        cout << "4. Back to Previous Menu\n";
                        cout << "0. Exit\n";
                        cout << "Enter your choice: ";
                        cin >> subChoice;

                        if (subChoice == 0) {
                    cout << "Exiting...\n";
                    return 0;
                } else if (subChoice == 4) {
                	authSystem.login();
                    
                }

                        int id, quantity;
                        double unitPrice;
                        string name;
                        switch (subChoice) {
                        case 1:
                            cout << "Enter Item ID: ";
                            cin >> id;
                            cin.ignore();
                            cout << "Enter Item Name: ";
                            getline(cin, name);
                            cout << "Enter Quantity: ";
                            cin >> quantity;
                            cout << "Enter Unit Price: ";
                            cin >> unitPrice;
                            billingManager.addItem(id, name, quantity, unitPrice);
                            break;
                        case 2:
                            billingManager.displayBill();
                            break;
                        case 3:
                            billingManager.processPayment();
                            break;
                        default:
                            cout << "Invalid choice. Try again.\n";
                        }
                    }
                    break;
                }
                default:
                    cout << "Invalid choice. Try again.\n";
                
            
            break;
        }

        case 3:
            cout << "Exiting the program. Goodbye!\n";
            break;
}
        
}

    return 0;
}
