#include "bytebuffer_api_openssl.h"
#include "bytebuffer_api_cryptopp.h"

#include <iostream>
#include <sstream>

namespace INTEROP_TEST_ECIES {

    unsigned char pub_key_der[] = {
    0x30, 0x82, 0x01, 0x4b, 0x30, 0x82, 0x01, 0x03, 0x06, 0x07, 0x2a, 0x86,
    0x48, 0xce, 0x3d, 0x02, 0x01, 0x30, 0x81, 0xf7, 0x02, 0x01, 0x01, 0x30,
    0x2c, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x01, 0x01, 0x02, 0x21,
    0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x30, 0x5b, 0x04,
    0x20, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x04, 0x20, 0x5a,
    0xc6, 0x35, 0xd8, 0xaa, 0x3a, 0x93, 0xe7, 0xb3, 0xeb, 0xbd, 0x55, 0x76,
    0x98, 0x86, 0xbc, 0x65, 0x1d, 0x06, 0xb0, 0xcc, 0x53, 0xb0, 0xf6, 0x3b,
    0xce, 0x3c, 0x3e, 0x27, 0xd2, 0x60, 0x4b, 0x03, 0x15, 0x00, 0xc4, 0x9d,
    0x36, 0x08, 0x86, 0xe7, 0x04, 0x93, 0x6a, 0x66, 0x78, 0xe1, 0x13, 0x9d,
    0x26, 0xb7, 0x81, 0x9f, 0x7e, 0x90, 0x04, 0x41, 0x04, 0x6b, 0x17, 0xd1,
    0xf2, 0xe1, 0x2c, 0x42, 0x47, 0xf8, 0xbc, 0xe6, 0xe5, 0x63, 0xa4, 0x40,
    0xf2, 0x77, 0x03, 0x7d, 0x81, 0x2d, 0xeb, 0x33, 0xa0, 0xf4, 0xa1, 0x39,
    0x45, 0xd8, 0x98, 0xc2, 0x96, 0x4f, 0xe3, 0x42, 0xe2, 0xfe, 0x1a, 0x7f,
    0x9b, 0x8e, 0xe7, 0xeb, 0x4a, 0x7c, 0x0f, 0x9e, 0x16, 0x2b, 0xce, 0x33,
    0x57, 0x6b, 0x31, 0x5e, 0xce, 0xcb, 0xb6, 0x40, 0x68, 0x37, 0xbf, 0x51,
    0xf5, 0x02, 0x21, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbc, 0xe6, 0xfa, 0xad,
    0xa7, 0x17, 0x9e, 0x84, 0xf3, 0xb9, 0xca, 0xc2, 0xfc, 0x63, 0x25, 0x51,
    0x02, 0x01, 0x01, 0x03, 0x42, 0x00, 0x04, 0x4f, 0xe7, 0x7b, 0xb6, 0xbb,
    0x54, 0x42, 0x39, 0xed, 0x5d, 0xe5, 0x40, 0xc8, 0xd8, 0x71, 0xca, 0x6d,
    0x83, 0x71, 0xd1, 0x88, 0x2a, 0x65, 0x00, 0x6c, 0xc6, 0x2f, 0x01, 0x31,
    0x49, 0xbe, 0x76, 0x7a, 0x67, 0x6a, 0x28, 0x33, 0xc7, 0x5b, 0xb9, 0x24,
    0x45, 0x24, 0x6e, 0xf0, 0x6d, 0x2f, 0x34, 0x06, 0x53, 0x73, 0x6a, 0xff,
    0x90, 0x90, 0xc1, 0x6d, 0x9b, 0x94, 0x0d, 0x0e, 0x1f, 0x95, 0x65,
    };

    unsigned char priv_key_der[] = {
        0x30, 0x82, 0x01, 0x68, 0x02, 0x01, 0x01, 0x04, 0x20, 0x51, 0x77, 0xae,
        0xf4, 0x18, 0xf4, 0x6b, 0xc4, 0xe5, 0xbb, 0xe9, 0xe6, 0x9e, 0x6d, 0xb0,
        0xea, 0x12, 0xf9, 0xf3, 0xdb, 0x9d, 0x56, 0x59, 0xf7, 0x5a, 0x17, 0xd7,
        0xd1, 0xe4, 0xd7, 0x47, 0x28, 0xa0, 0x81, 0xfa, 0x30, 0x81, 0xf7, 0x02,
        0x01, 0x01, 0x30, 0x2c, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x01,
        0x01, 0x02, 0x21, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0x30, 0x5b, 0x04, 0x20, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
        0x04, 0x20, 0x5a, 0xc6, 0x35, 0xd8, 0xaa, 0x3a, 0x93, 0xe7, 0xb3, 0xeb,
        0xbd, 0x55, 0x76, 0x98, 0x86, 0xbc, 0x65, 0x1d, 0x06, 0xb0, 0xcc, 0x53,
        0xb0, 0xf6, 0x3b, 0xce, 0x3c, 0x3e, 0x27, 0xd2, 0x60, 0x4b, 0x03, 0x15,
        0x00, 0xc4, 0x9d, 0x36, 0x08, 0x86, 0xe7, 0x04, 0x93, 0x6a, 0x66, 0x78,
        0xe1, 0x13, 0x9d, 0x26, 0xb7, 0x81, 0x9f, 0x7e, 0x90, 0x04, 0x41, 0x04,
        0x6b, 0x17, 0xd1, 0xf2, 0xe1, 0x2c, 0x42, 0x47, 0xf8, 0xbc, 0xe6, 0xe5,
        0x63, 0xa4, 0x40, 0xf2, 0x77, 0x03, 0x7d, 0x81, 0x2d, 0xeb, 0x33, 0xa0,
        0xf4, 0xa1, 0x39, 0x45, 0xd8, 0x98, 0xc2, 0x96, 0x4f, 0xe3, 0x42, 0xe2,
        0xfe, 0x1a, 0x7f, 0x9b, 0x8e, 0xe7, 0xeb, 0x4a, 0x7c, 0x0f, 0x9e, 0x16,
        0x2b, 0xce, 0x33, 0x57, 0x6b, 0x31, 0x5e, 0xce, 0xcb, 0xb6, 0x40, 0x68,
        0x37, 0xbf, 0x51, 0xf5, 0x02, 0x21, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00,
        0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbc,
        0xe6, 0xfa, 0xad, 0xa7, 0x17, 0x9e, 0x84, 0xf3, 0xb9, 0xca, 0xc2, 0xfc,
        0x63, 0x25, 0x51, 0x02, 0x01, 0x01, 0xa1, 0x44, 0x03, 0x42, 0x00, 0x04,
        0x4f, 0xe7, 0x7b, 0xb6, 0xbb, 0x54, 0x42, 0x39, 0xed, 0x5d, 0xe5, 0x40,
        0xc8, 0xd8, 0x71, 0xca, 0x6d, 0x83, 0x71, 0xd1, 0x88, 0x2a, 0x65, 0x00,
        0x6c, 0xc6, 0x2f, 0x01, 0x31, 0x49, 0xbe, 0x76, 0x7a, 0x67, 0x6a, 0x28,
        0x33, 0xc7, 0x5b, 0xb9, 0x24, 0x45, 0x24, 0x6e, 0xf0, 0x6d, 0x2f, 0x34,
        0x06, 0x53, 0x73, 0x6a, 0xff, 0x90, 0x90, 0xc1, 0x6d, 0x9b, 0x94, 0x0d,
        0x0e, 0x1f, 0x95, 0x65,
    };


    void test_static_keys_cryptopp_encrypt_openssl_decrypt()
    {
        char message[] = "It was the best of times.";

        int encryptedBufferSize;
        byte* cipherText;

        cipherText = BYTE_BUFFERIZED_CRYPTOPP::DsaEncryptBuffer(pub_key_der, sizeof(pub_key_der), (byte*)message, sizeof(message), &encryptedBufferSize);

        int decryptedBufferSize;

        byte* plainText;
        plainText = BYTE_BUFFERIZED_OPENSSL::DsaDecryptBuffer(priv_key_der, sizeof(priv_key_der), cipherText, encryptedBufferSize, &decryptedBufferSize);

        if (strcmp(message, (char*)plainText) != 0)
        {
            std::cout << "FAIL  " << "ECIES   " << "static keys cryptopp encrypt openssl decrypt" << '\n';
        }
        free(cipherText);
        free(plainText);
    }

    void test_static_keys_openssl_encrypt_cryptopp_decrypt() // this fails
    {
        char message[] = "It was the worst of times";

        int encryptedBufferSize;
        byte* cipherText;
        cipherText = BYTE_BUFFERIZED_OPENSSL::DsaEncryptBuffer(pub_key_der, sizeof(pub_key_der), (byte*)message, sizeof(message), &encryptedBufferSize);

        int decryptedBufferSize;

        byte* plainText;
        plainText = BYTE_BUFFERIZED_CRYPTOPP::DsaDecryptBuffer(priv_key_der, sizeof(priv_key_der), cipherText, encryptedBufferSize, &decryptedBufferSize);
        // crypto++ can't decode the private key, these two example keys are copied from OpenSSL demo code

        if (strcmp(message, (char*)plainText) != 0)
        {
            std::cout << "FAIL  " << "ECIES  " << "static keys openssl encrypt cryptopp decrypt" << '\n';
        }
        free(cipherText);
        free(plainText);
    }


    enum LIB
    {
        CRYPTOPP = 0,
        OPENSSL = 1
    };

    char const* lib_names[] = { "Crypto++", "OpenSSL" };
    LIB libraries[2] = { LIB::CRYPTOPP, LIB::OPENSSL };

    static void test(LIB keygen, LIB encrypt_lib, LIB decrypt_lib)
    {
        std::stringstream ss;
        ss << "ECIES  Test  " << lib_names[keygen] << "  generate keys   " << lib_names[encrypt_lib] << "  encrypt  " << lib_names[decrypt_lib] << "  decrypt\n";
        
        char message[] = "It was the best of times";

        byte* pub = NULL, * pri = NULL;
        int pubLen, priLen;

        int encryptedBufferSize;
        byte* cipherText = NULL;

        int decryptedBufferSize;
        byte* plainText = NULL;

        if (keygen == LIB::CRYPTOPP)
            BYTE_BUFFERIZED_CRYPTOPP::DsaGenerateKeyPair(&pri, &priLen, &pub, &pubLen);
        else if (keygen == LIB::OPENSSL)
            BYTE_BUFFERIZED_OPENSSL::DsaGenerateKeyPair(&pri, &priLen, &pub, &pubLen);

        if (pub == NULL || pri == NULL)
        {
            std::cout << "FAIL  " << ss.str();
            goto cleanup;
        }

        if (encrypt_lib == LIB::CRYPTOPP)
            cipherText = BYTE_BUFFERIZED_CRYPTOPP::DsaEncryptBuffer(pub, pubLen, (byte*)message, sizeof(message), &encryptedBufferSize);
        else if (encrypt_lib == LIB::OPENSSL)
            cipherText = BYTE_BUFFERIZED_OPENSSL::DsaEncryptBuffer(pub, pubLen, (byte*)message, sizeof(message), &encryptedBufferSize);

        if (decrypt_lib == LIB::CRYPTOPP)
            plainText = BYTE_BUFFERIZED_CRYPTOPP::DsaDecryptBuffer(pri, priLen, cipherText, encryptedBufferSize, &decryptedBufferSize);
        else if (decrypt_lib == LIB::OPENSSL)
            plainText = BYTE_BUFFERIZED_OPENSSL::DsaDecryptBuffer(pri, priLen, cipherText, encryptedBufferSize, &decryptedBufferSize);

        if (strcmp(message, (char*)plainText) == 0)
        {
            std::cout << "PASS  " << ss.str();
        }
        else
        {
            std::cout << "FAIL  " << ss.str();
        }

    cleanup:

        if (pub)
            free(pub);
        if (pri)
            free(pri);
        if (cipherText)
            free(cipherText);
        if (plainText)
            free(plainText);
    }

    void test_ECIES()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    test(libraries[i], libraries[j], libraries[k]);
                }
            }
        }
    }


    void test_cryptopp_generate_keys_cryptopp_encrypt_openssl_decrypt()
    {
        char message[] = "It was the best of times";

        byte* pub = NULL, * pri = NULL;
        int pubLen, priLen;

        int encryptedBufferSize;
        byte* cipherText = NULL;

        int decryptedBufferSize;
        byte* plainText = NULL;

        BYTE_BUFFERIZED_CRYPTOPP::DsaGenerateKeyPair(&pri, &priLen, &pub, &pubLen);

        if (pub == NULL || pri == NULL)
        {
            std::cout << "FAIL  " << "ECIES  " << "cryptopp generate keys cryptopp encrypt openssl decrypt";
            goto cleanup;
        }
        cipherText = BYTE_BUFFERIZED_CRYPTOPP::DsaEncryptBuffer(pub, pubLen, (byte*)message, sizeof(message), &encryptedBufferSize);

        plainText = BYTE_BUFFERIZED_OPENSSL::DsaDecryptBuffer(pri, priLen, cipherText, encryptedBufferSize, &decryptedBufferSize);

        if (strcmp(message, (char*)plainText) != 0)
        {
            std::cout << "FAIL  " << "ECIES  " << "cryptopp generate keys cryptopp encrypt openssl decrypt";
        }

    cleanup:

        if (pub)
            free(pub);
        if (pri)
            free(pri);
        if (cipherText)
            free(cipherText);
        if (plainText)
            free(plainText);
    }

    void test_cryptopp_generate_keys_openssl_encrypt_cryptopp_decrypt()
    {
        char message[] = "It was the best of times";

        byte* pub = NULL, * pri = NULL;
        int pubLen, priLen;

        int encryptedBufferSize;
        byte* cipherText = NULL;
        int decryptedBufferSize;
        byte* plainText = NULL;

        BYTE_BUFFERIZED_CRYPTOPP::DsaGenerateKeyPair(&pri, &priLen, &pub, &pubLen);
        if (pub == NULL || pri == NULL)
        {
            std::cout << "FAIL  " << "ECIES  " << "cryptopp generate keys openssl encrypt cryptopp decrypt";
            goto cleanup;
        }
        cipherText = BYTE_BUFFERIZED_OPENSSL::DsaEncryptBuffer(pub, pubLen, (byte*)message, sizeof(message), &encryptedBufferSize);

        plainText = BYTE_BUFFERIZED_CRYPTOPP::DsaDecryptBuffer(pri, priLen, cipherText, encryptedBufferSize, &decryptedBufferSize);

        if (strcmp(message, (char*)plainText) != 0)
        {
            std::cout << "FAIL  " << "ECIES  " << "cryptopp generate keys openssl encrypt cryptopp decrypt";
        }

    cleanup:

        if (pub)
            free(pub);
        if (pri)
            free(pri);
        if (cipherText)
            free(cipherText);
        if (plainText)
            free(plainText);
    }

    void test_cryptopp_generate_keys_openssl_encrypt_openssl_decrypt()
    {
        char message[] = "It was the best of times";

        byte* pub = NULL, * pri = NULL;
        int pubLen, priLen;

        int encryptedBufferSize;
        byte* cipherText = NULL;

        int decryptedBufferSize;
        byte* plainText = NULL;

        BYTE_BUFFERIZED_CRYPTOPP::DsaGenerateKeyPair(&pri, &priLen, &pub, &pubLen);
        if (pub == NULL || pri == NULL)
        {
            std::cout << "FAIL  " << "ECIES  " << "cryptopp generate keys openssl encrypt openssl decrypt";
            goto cleanup;
        }
        cipherText = BYTE_BUFFERIZED_OPENSSL::DsaEncryptBuffer(pub, pubLen, (byte*)message, sizeof(message), &encryptedBufferSize);

        plainText = BYTE_BUFFERIZED_OPENSSL::DsaDecryptBuffer(pri, priLen, cipherText, encryptedBufferSize, &decryptedBufferSize);

        if (strcmp(message, (char*)plainText) != 0)
        {
            std::cout << "FAIL  " << "ECIES  " << "cryptopp generate keys openssl encrypt openssl decrypt";
        }

    cleanup:

        if (pub)
            free(pub);
        if (pri)
            free(pri);
        if (cipherText)
            free(cipherText);
        if (plainText)
            free(plainText);
    }

    void test_openssl_generate_keys_cryptopp_encrypt_openssl_decrypt()
    {
        char message[] = "It was the best of times";

        byte* pub = NULL, * pri = NULL;
        int pubLen, priLen;

        int encryptedBufferSize;
        byte* cipherText = NULL;

        int decryptedBufferSize;
        byte* plainText = NULL;

        BYTE_BUFFERIZED_OPENSSL::DsaGenerateKeyPair(&pri, &priLen, &pub, &pubLen);
        if (pub == NULL || pri == NULL)
        {
            std::cout << "FAIL  " << "ECIES  " << "openssl generate keys cryptopp encrypt openssl decrypt";
            goto cleanup;
        }

        cipherText = BYTE_BUFFERIZED_CRYPTOPP::DsaEncryptBuffer(pub, pubLen, (byte*)message, sizeof(message), &encryptedBufferSize);

        plainText = BYTE_BUFFERIZED_OPENSSL::DsaDecryptBuffer(pri, priLen, cipherText, encryptedBufferSize, &decryptedBufferSize);

        if (strcmp(message, (char*)plainText) != 0)
        {
            std::cout << "FAIL  " << "ECIES  " << "openssl generate keys cryptopp encrypt openssl decrypt";
        }

    cleanup:

        if (pub)
            free(pub);
        if (pri)
            free(pri);
        if (cipherText)
            free(cipherText);
        if (plainText)
            free(plainText);
    }

    void test_openssl_generate_keys_openssl_encrypt_cryptopp_decrypt()
    {
        char message[] = "It was the best of times";

        byte* pub = NULL, * pri = NULL;

        int pubLen, priLen;

        int encryptedBufferSize;
        byte* cipherText = NULL;

        int decryptedBufferSize;

        byte* plainText = NULL;


        BYTE_BUFFERIZED_OPENSSL::DsaGenerateKeyPair(&pri, &priLen, &pub, &pubLen);
        if (pub == NULL || pri == NULL)
        {
            std::cout << "FAIL  " << "ECIES  " << "openssl generate keys openssl encrypt cryptopp decrypt";
            goto cleanup;
        }

        cipherText = BYTE_BUFFERIZED_OPENSSL::DsaEncryptBuffer(pub, pubLen, (byte*)message, sizeof(message), &encryptedBufferSize);

        plainText = BYTE_BUFFERIZED_CRYPTOPP::DsaDecryptBuffer(pri, priLen, cipherText, encryptedBufferSize, &decryptedBufferSize);

        if (strcmp(message, (char*)plainText) != 0)
        {
            std::cout << "FAIL  " << "ECIES  " << "openssl generate keys openssl encrypt cryptopp decrypt";
        }

    cleanup:

        if (pub)
            free(pub);
        if (pri)
            free(pri);
        if (cipherText)
            free(cipherText);
        if (plainText)
            free(plainText);
    }

    void test_openssl_generate_keys_openssl_encrypt_openssl_decrypt()
    {
        char message[] = "It was the best of times";

        byte* pub = NULL, * pri = NULL;

        int pubLen, priLen;

        int encryptedBufferSize;
        byte* cipherText = NULL;

        int decryptedBufferSize;

        byte* plainText = NULL;

        BYTE_BUFFERIZED_OPENSSL::DsaGenerateKeyPair(&pri, &priLen, &pub, &pubLen);
        if (pub == NULL || pri == NULL)
        {
            std::cout << "FAIL  " << "ECIES  " << "openssl generate keys openssl encrypt openssl decrypt";
            goto cleanup;
        }

        cipherText = BYTE_BUFFERIZED_OPENSSL::DsaEncryptBuffer(pub, pubLen, (byte*)message, sizeof(message), &encryptedBufferSize);

        plainText = BYTE_BUFFERIZED_OPENSSL::DsaDecryptBuffer(pri, priLen, cipherText, encryptedBufferSize, &decryptedBufferSize);
        if (strcmp(message, (char*)plainText) != 0)
        {
            std::cout << "FAIL  " << "ECIES  " << "openssl generate keys openssl encrypt openssl decrypt";
        }

    cleanup:

        if (pub)
            free(pub);
        if (pri)
            free(pri);
        if (cipherText)
            free(cipherText);
        if (plainText)
            free(plainText);
    }

    void test_openssl_generate_keys_cryptopp_encrypt_cryptopp_decrypt()
    {
        char message[] = "It was the best of times";

        byte* pub = NULL, * pri = NULL;
        int pubLen, priLen;

        int encryptedBufferSize;
        byte* cipherText = NULL;

        int decryptedBufferSize;
        byte* plainText = NULL;

        BYTE_BUFFERIZED_OPENSSL::DsaGenerateKeyPair(&pri, &priLen, &pub, &pubLen);
        if (pub == NULL || pri == NULL)
        {
            std::cout << "FAIL  " << "ECIES  " << "openssl generate keys cryptopp encrypt cryptopp decrypt";
            goto cleanup;
        }
        cipherText = BYTE_BUFFERIZED_CRYPTOPP::DsaEncryptBuffer(pub, pubLen, (byte*)message, sizeof(message), &encryptedBufferSize);

        plainText = BYTE_BUFFERIZED_CRYPTOPP::DsaDecryptBuffer(pri, priLen, cipherText, encryptedBufferSize, &decryptedBufferSize);
        if (strcmp(message, (char*)plainText) != 0)
        {
            std::cout << "FAIL  " << "ECIES  " << "openssl generate keys cryptopp encrypt cryptopp decrypt";
        }

    cleanup:

        if (pub)
            free(pub);
        if (pri)
            free(pri);
        if (cipherText)
            free(cipherText);
        if (plainText)
            free(plainText);
    }
}