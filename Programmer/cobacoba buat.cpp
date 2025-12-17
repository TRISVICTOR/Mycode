#include <stdio.h>                          // Include standard I/O library
#include <stdlib.h>                         // Include standard library for memory functions
#include <string.h>                         // Include string functions
#include <stdbool.h>                        // Include bool type support

#define ALPHABET_SIZE 26                    // Number of lowercase English letters
#define MAX_DESC 256                        // Maximum length for description
#define MAX_WORD 100                        // Maximum length for word

// Define TrieNode structure
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];  // Pointers to children nodes (a to z)
    bool isEndOfWord;                           // Flag to indicate end of word
    char description[MAX_DESC];                 // Description string
} TrieNode;

// Create a new Trie node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));  // Allocate memory
    node->isEndOfWord = false;                             // Set end flag to false
    node->description[0] = '\0';                           // Empty description
    for (int i = 0; i < ALPHABET_SIZE; i++)                // Loop through children
        node->children[i] = NULL;                          // Initialize children to NULL
    return node;                                           // Return the new node
}

// Validate if the slang word is valid (length > 1 and no spaces)
bool isValidWord(const char* word) {
    if (strlen(word) <= 1 || strchr(word, ' '))            // Check length and space
        return false;                                      // Invalid
    return true;                                           // Valid
}

// Validate description has more than one word
bool isValidDescription(const char* desc) {
    int wordCount = 0;                                     // Initialize word count
    const char* ptr = desc;                                // Pointer to string
    while (*ptr) {                                         // Loop through string
        while (*ptr == ' ') ptr++;                         // Skip spaces
        if (*ptr) wordCount++;                             // Count a word
        while (*ptr && *ptr != ' ') ptr++;                 // Move to next word
    }
    return wordCount > 1;                                  // Return true if more than 1 word
}

// Insert a word with description into the Trie
void insert(TrieNode* root, const char* word, const char* desc) {
    TrieNode* current = root;                              // Start from root
    for (int i = 0; word[i]; i++) {                         // Loop through characters
        int index = word[i] - 'a';                          // Get index for character
        if (!current->children[index])                     // If no child
            current->children[index] = createNode();       // Create child
        current = current->children[index];                // Move to child
    }
    current->isEndOfWord = true;                           // Mark end of word
    strcpy(current->description, desc);                    // Store description
}

// Search a word in the Trie
TrieNode* search(TrieNode* root, const char* word) {
    TrieNode* current = root;                              // Start from root
    for (int i = 0; word[i]; i++) {                         // Loop through characters
        int index = word[i] - 'a';                          // Get index
        if (!current->children[index]) return NULL;        // If not found, return NULL
        current = current->children[index];                // Move to child
    }
    return current->isEndOfWord ? current : NULL;          // Return node if it's a word
}

// Helper to print all words from a given Trie node
void printWordsWithPrefix(TrieNode* root, char* prefix, int level) {
    if (root->isEndOfWord) {                               // If end of word
        prefix[level] = '\0';                              // Null terminate
        printf("%s\n", prefix);                            // Print the word
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {              // Check all children
        if (root->children[i]) {                           // If child exists
            prefix[level] = i + 'a';                       // Add letter to prefix
            printWordsWithPrefix(root->children[i], prefix, level + 1);  // Recurse
        }
    }
}

// Find and print all words starting with a prefix
void findByPrefix(TrieNode* root, const char* prefix) {
    TrieNode* current = root;                              // Start from root
    for (int i = 0; prefix[i]; i++) {                       // Traverse to prefix end
        int index = prefix[i] - 'a';                        // Index
        if (!current->children[index]) {                   // Not found
            printf("There is no prefix \"%s\" in the dictionary.\n", prefix); // Message
            return;                                        // Exit
        }
        current = current->children[index];                // Move to child
    }

    char buffer[MAX_WORD];                                 // Temp buffer
    strcpy(buffer, prefix);                                // Copy prefix
    printWordsWithPrefix(current, buffer, strlen(prefix)); // Print words
}

// Print all words in the Trie
void viewAllWords(TrieNode* root, char* buffer, int level) {
    if (root->isEndOfWord) {                               // If end of word
        buffer[level] = '\0';                              // Null terminate
        printf("%s\n", buffer);                            // Print word
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {              // Loop through children
        if (root->children[i]) {                           // If child exists
            buffer[level] = i + 'a';                       // Add char to buffer
            viewAllWords(root->children[i], buffer, level + 1); // Recurse
        }
    }
}

// Display the main menu
void menu() {
    printf("\n1. Release a new slang word\n");             // Option 1
    printf("2. Search a slang word\n");                    // Option 2
    printf("3. View all slang words starting with a certain prefix\n"); // Option 3
    printf("4. View all slang words\n");                   // Option 4
    printf("5. Exit\n");                                   // Option 5
    printf(">> Choose: ");                                 // Prompt
}

// Main function
int main() {
    TrieNode* root = createNode();                         // Initialize root node
    int choice;                                            // Menu choice
    char word[MAX_WORD], desc[MAX_DESC], buffer[MAX_WORD]; // Buffers

    do {
        menu();                                            // Show menu
        scanf("%d", &choice);                              // Get user input
        getchar();                                         // Consume newline

        switch (choice) {
		    case 1: {
		        do {
		            printf("\nInput a new slang word [Must be more than 1 characters and contains no space]: ");
		            scanf("%s", word);
		            while (getchar() != '\n');
		        } while (!isValidWord(word));
		
		        do {
		            printf("Input a new slang word description [Must be more than 2 words]: ");
		            fgets(desc, MAX_DESC, stdin);
		            desc[strcspn(desc, "\n")] = '\0';
		        } while (!isValidDescription(desc));
		
		        TrieNode* node = search(root, word);
		        if (node) {
		            strcpy(node->description, desc);
		            printf("\nSuccessfully updated a slang word.\n");
		        } else {
		            insert(root, word, desc);
		            printf("\nSuccessfully released new slang word.\n");
		        }
		        break;
		    }
		
		    case 2: {
		        do {
		            printf("\nInput a slang word to be searched [Must be more than 1 characters and contains no space]: ");
		            scanf("%s", word);
		        } while (!isValidWord(word));
		
		        TrieNode* node = search(root, word);
		        if (node) {
		            printf("\nSlang word  : %s\n", word);
		            printf("Description : %s\n", node->description);
		        } else {
		            printf("\nThere is no word \"%s\" in the dictionary.\n", word);
		        }
		        break;
		    }
		
		    case 3: {
		        printf("\nInput a prefix to be searched: ");
		        scanf("%s", word);
		        printf("\nWords starts with \"%s\":\n", word);
		        findByPrefix(root, word);
		        break;
		    }
		
		    case 4: {
		        printf("\nList of all slang words in the dictionary:\n");
		        viewAllWords(root, buffer, 0);
		        break;
		    }
		
		    case 5: {
		        printf("\nThank you... Have a nice day :)\n");
		        break;
		    }
		}

        if (choice != 5) {                                 // Wait for Enter
            printf("\nPress enter to continue...");
            getchar();
        }

    } while (choice != 5);                                 // Loop until exit

    return 0;                                              // End program
}

