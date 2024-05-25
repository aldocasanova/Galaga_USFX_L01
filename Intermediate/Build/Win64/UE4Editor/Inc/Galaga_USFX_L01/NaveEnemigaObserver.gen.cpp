// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/NaveEnemigaObserver.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNaveEnemigaObserver() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UNaveEnemigaObserver_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UNaveEnemigaObserver();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void UNaveEnemigaObserver::StaticRegisterNativesUNaveEnemigaObserver()
	{
	}
	UClass* Z_Construct_UClass_UNaveEnemigaObserver_NoRegister()
	{
		return UNaveEnemigaObserver::StaticClass();
	}
	struct Z_Construct_UClass_UNaveEnemigaObserver_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNaveEnemigaObserver_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNaveEnemigaObserver_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "NaveEnemigaObserver.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNaveEnemigaObserver_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<INaveEnemigaObserver>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UNaveEnemigaObserver_Statics::ClassParams = {
		&UNaveEnemigaObserver::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UNaveEnemigaObserver_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UNaveEnemigaObserver_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UNaveEnemigaObserver()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UNaveEnemigaObserver_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UNaveEnemigaObserver, 4203291279);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<UNaveEnemigaObserver>()
	{
		return UNaveEnemigaObserver::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNaveEnemigaObserver(Z_Construct_UClass_UNaveEnemigaObserver, &UNaveEnemigaObserver::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("UNaveEnemigaObserver"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNaveEnemigaObserver);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
