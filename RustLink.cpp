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
    void* yx_games_key_create(const char* EncryptionKey);
    const char* yx_games_key_encrypt(void* YXEncryptionPTR, const char* Data);
    const char* yx_games_key_decrypt(void* YXEncryptionPTR, const char* Data);
    void yx_games_key_destroy(void* YXEncryptionPTR);
}

int main() {
    // This is loaded in first connect - YX Games Login
    const char* YXKey = "TestEncryption";
    // Create a PTR for YXGames Encryption
    void* YXEncryptionPTR = yx_games_key_create(YXKey);

    const char* input = "Hello, YXGames Server!";

    // Encrypt the input data
    const char* encryptedInput = yx_games_key_encrypt(YXEncryptionPTR, input);
    std::cout << "Encrypted Input: " << encryptedInput << std::endl;

    // Decrypt the input data
    const char* decryptedInput = yx_games_key_decrypt(YXEncryptionPTR, encryptedInput);
    std::cout << "Decrypted Input: " << decryptedInput << std::endl;

    // Free Memory
    yx_games_key_destroy(YXEncryptionPTR);

    return 0;
}
