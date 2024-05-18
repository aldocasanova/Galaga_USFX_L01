// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/CanonHieloNv1.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCanonHieloNv1() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonHieloNv1_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonHieloNv1();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonHielo();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void ACanonHieloNv1::StaticRegisterNativesACanonHieloNv1()
	{
	}
	UClass* Z_Construct_UClass_ACanonHieloNv1_NoRegister()
	{
		return ACanonHieloNv1::StaticClass();
	}
	struct Z_Construct_UClass_ACanonHieloNv1_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACanonHieloNv1_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACanonHielo,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACanonHieloNv1_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CanonHieloNv1.h" },
		{ "ModuleRelativePath", "CanonHieloNv1.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACanonHieloNv1_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACanonHieloNv1>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACanonHieloNv1_Statics::ClassParams = {
		&ACanonHieloNv1::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ACanonHieloNv1_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACanonHieloNv1_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACanonHieloNv1()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACanonHieloNv1_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACanonHieloNv1, 1658287554);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ACanonHieloNv1>()
	{
		return ACanonHieloNv1::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACanonHieloNv1(Z_Construct_UClass_ACanonHieloNv1, &ACanonHieloNv1::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ACanonHieloNv1"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACanonHieloNv1);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
