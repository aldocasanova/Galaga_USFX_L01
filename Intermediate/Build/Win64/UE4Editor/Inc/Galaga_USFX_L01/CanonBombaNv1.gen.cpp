// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/CanonBombaNv1.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCanonBombaNv1() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonBombaNv1_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonBombaNv1();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACanonBomba();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void ACanonBombaNv1::StaticRegisterNativesACanonBombaNv1()
	{
	}
	UClass* Z_Construct_UClass_ACanonBombaNv1_NoRegister()
	{
		return ACanonBombaNv1::StaticClass();
	}
	struct Z_Construct_UClass_ACanonBombaNv1_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACanonBombaNv1_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACanonBomba,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACanonBombaNv1_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CanonBombaNv1.h" },
		{ "ModuleRelativePath", "CanonBombaNv1.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACanonBombaNv1_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACanonBombaNv1>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACanonBombaNv1_Statics::ClassParams = {
		&ACanonBombaNv1::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ACanonBombaNv1_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACanonBombaNv1_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACanonBombaNv1()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACanonBombaNv1_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACanonBombaNv1, 2122126095);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ACanonBombaNv1>()
	{
		return ACanonBombaNv1::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACanonBombaNv1(Z_Construct_UClass_ACanonBombaNv1, &ACanonBombaNv1::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ACanonBombaNv1"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACanonBombaNv1);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
