// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/CanonBalaNv3.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCanonBalaNv3() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonBalaNv3_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonBalaNv3();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonBala();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void ACanonBalaNv3::StaticRegisterNativesACanonBalaNv3()
	{
	}
	UClass* Z_Construct_UClass_ACanonBalaNv3_NoRegister()
	{
		return ACanonBalaNv3::StaticClass();
	}
	struct Z_Construct_UClass_ACanonBalaNv3_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACanonBalaNv3_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACanonBala,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACanonBalaNv3_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CanonBalaNv3.h" },
		{ "ModuleRelativePath", "CanonBalaNv3.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACanonBalaNv3_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACanonBalaNv3>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACanonBalaNv3_Statics::ClassParams = {
		&ACanonBalaNv3::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ACanonBalaNv3_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACanonBalaNv3_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACanonBalaNv3()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACanonBalaNv3_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACanonBalaNv3, 3398523196);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ACanonBalaNv3>()
	{
		return ACanonBalaNv3::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACanonBalaNv3(Z_Construct_UClass_ACanonBalaNv3, &ACanonBalaNv3::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ACanonBalaNv3"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACanonBalaNv3);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
