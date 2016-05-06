// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"
#include <string>
#include <vector>

using namespace std;

class FSodiumUE4Module : public IModuleInterface
{
public:

	////////////////////////////
	// IModuleInterface implementation
	////////////////////////////

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	bool Test();

	void GenerateKeyPair(unsigned char *pk, unsigned char *sk);

	int GetPublicKeyBytes();
	int GetSecretKeyBytes();
	int GetBoxSealBytes();

	void RandomBytes(unsigned char* bytes, size_t len);

	int Encrypt(vector<unsigned char>& encrypted, unsigned char *data, size_t data_len, unsigned char *pk);
	int Decrypt(unsigned char *encrypted, size_t data_len, vector<unsigned char>& decrypted, unsigned char *pk, unsigned char *sk);

	static inline FSodiumUE4Module& Get(){
		return FModuleManager::LoadModuleChecked<FSodiumUE4Module>("SodiumUE4"); // name should be the same as directory of the plugin in /Plugins
	}

	static inline bool IsAvailable() {
		return FModuleManager::Get().IsModuleLoaded("SodiumUE4");
	}
	

private:
	/** Handle to the test dll we will load */
	void*	libsodiumUE4Handle;
};