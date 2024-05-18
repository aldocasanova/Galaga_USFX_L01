// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/CanonBala.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCanonBala() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonBala_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonBala();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AModeloCanon();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void ACanonBala::StaticRegisterNativesACanonBala()
	{
	}
	UClass* Z_Construct_UClass_ACanonBala_NoRegister()
	{
		return ACanonBala::StaticClass();
	}
	struct Z_Construct_UClass_ACanonBala_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACanonBala_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AModeloCanon,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACanonBala_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CanonBala.h" },
		{ "ModuleRelativePath", "CanonBala.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACanonBala_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACanonBala>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACanonBala_Statics::ClassParams = {
		&ACanonBala::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ACanonBala_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACanonBala_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACanonBala()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACanonBala_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACanonBala, 1093819420);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ACanonBala>()
	{
		return ACanonBala::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACanonBala(Z_Construct_UClass_ACanonBala, &ACanonBala::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ACanonBala"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACanonBala);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
