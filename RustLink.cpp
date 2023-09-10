#include <iostream>
#include <cstring>

/**
* Server Sided Key Packets Encrypt and Decrypt - YeXiuPH
* Started: 9/8/2023
* Finalized: 9/11/2023
* Status: Binded
* Client Side Bind: Untested
* Server Side Bind: Tested | Working
*/

extern "C" {
    const char* create_key();
    void* yx_games_key_create();
    const char* yx_games_key_encrypt(void* YXEncryptionPTR, const char* Data);
    const char* yx_games_key_decrypt(void* YXEncryptionPTR, const char* Data);
    void yx_games_key_destroy(void* YXEncryptionPTR);
}

int main() {
    // Get the encrypted key from Server Side
    const char* encryptedKey = create_key();
    std::cout << "Encrypted Key: " << encryptedKey << std::endl;
    const char* expectedKey = "SKyZdHJzsjKZoltLz6MTYrKQjzEwC5FJ2x0n2mJPEGc=";

    // Compare the obtained key with the expected key
    if (strcmp(encryptedKey, expectedKey) == 0) {
        std::cout << "Encrypted Key matches the expected value." << std::endl;
    }
    else {
        std::cout << "Encrypted Key does not match the expected value." << std::endl;
    }

    // Create a PTR for YXGames Encryption
    void* YXEncryptionPTR = yx_games_key_create();
    const char* input = "Hello, YXGames Server!";

    // Encrypt the input data
    const char* encryptedInput = yx_games_key_encrypt(YXEncryptionPTR, input);
    std::cout << "Encrypted Input: " << encryptedInput << std::endl;

    const char* expectedInput = "4hNit7i5+xpzYIbB7mb1U80jOQVbDh6hUAhSqn+CjI8=";

    // Compare the obtained encrypted input with the expected input
    if (strcmp(encryptedInput, expectedInput) == 0) {
        std::cout << "Encrypted Input matches the expected value." << std::endl;
    }
    else {
        std::cout << "Encrypted Input does not match the expected value." << std::endl;
    }

    // Decrypt the input data
    const char* decryptedInput = yx_games_key_decrypt(YXEncryptionPTR, encryptedInput);
    std::cout << "Decrypted Input: " << decryptedInput << std::endl;

    // Free Memory
    yx_games_key_destroy(YXEncryptionPTR);

    return 0;
}
