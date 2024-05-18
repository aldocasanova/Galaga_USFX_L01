// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/CanonLazer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCanonLazer() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonLazer_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonLazer();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AModeloCanon();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void ACanonLazer::StaticRegisterNativesACanonLazer()
	{
	}
	UClass* Z_Construct_UClass_ACanonLazer_NoRegister()
	{
		return ACanonLazer::StaticClass();
	}
	struct Z_Construct_UClass_ACanonLazer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACanonLazer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AModeloCanon,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACanonLazer_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CanonLazer.h" },
		{ "ModuleRelativePath", "CanonLazer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACanonLazer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACanonLazer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACanonLazer_Statics::ClassParams = {
		&ACanonLazer::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACanonLazer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACanonLazer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACanonLazer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACanonLazer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACanonLazer, 1338024816);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ACanonLazer>()
	{
		return ACanonLazer::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACanonLazer(Z_Construct_UClass_ACanonLazer, &ACanonLazer::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ACanonLazer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACanonLazer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
