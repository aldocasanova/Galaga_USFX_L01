// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/Roca.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRoca() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ARoca_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ARoca();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UFieldElement_NoRegister();
// End Cross Module References
	void ARoca::StaticRegisterNativesARoca()
	{
	}
	UClass* Z_Construct_UClass_ARoca_NoRegister()
	{
		return ARoca::StaticClass();
	}
	struct Z_Construct_UClass_ARoca_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARoca_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARoca_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Roca.h" },
		{ "ModuleRelativePath", "Roca.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ARoca_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UFieldElement_NoRegister, (int32)VTABLE_OFFSET(ARoca, IFieldElement), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARoca_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARoca>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARoca_Statics::ClassParams = {
		&ARoca::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ARoca_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARoca_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARoca()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARoca_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARoca, 2489402869);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ARoca>()
	{
		return ARoca::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARoca(Z_Construct_UClass_ARoca, &ARoca::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ARoca"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARoca);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
