// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/CanonLazerNv3.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCanonLazerNv3() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonLazerNv3_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonLazerNv3();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonLazer();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void ACanonLazerNv3::StaticRegisterNativesACanonLazerNv3()
	{
	}
	UClass* Z_Construct_UClass_ACanonLazerNv3_NoRegister()
	{
		return ACanonLazerNv3::StaticClass();
	}
	struct Z_Construct_UClass_ACanonLazerNv3_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACanonLazerNv3_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACanonLazer,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACanonLazerNv3_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CanonLazerNv3.h" },
		{ "ModuleRelativePath", "CanonLazerNv3.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACanonLazerNv3_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACanonLazerNv3>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACanonLazerNv3_Statics::ClassParams = {
		&ACanonLazerNv3::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ACanonLazerNv3_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACanonLazerNv3_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACanonLazerNv3()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACanonLazerNv3_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACanonLazerNv3, 2048863320);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ACanonLazerNv3>()
	{
		return ACanonLazerNv3::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACanonLazerNv3(Z_Construct_UClass_ACanonLazerNv3, &ACanonLazerNv3::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ACanonLazerNv3"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACanonLazerNv3);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
