// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/Pilar.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePilar() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_APilar_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_APilar();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UFieldElement_NoRegister();
// End Cross Module References
	void APilar::StaticRegisterNativesAPilar()
	{
	}
	UClass* Z_Construct_UClass_APilar_NoRegister()
	{
		return APilar::StaticClass();
	}
	struct Z_Construct_UClass_APilar_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APilar_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APilar_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Pilar.h" },
		{ "ModuleRelativePath", "Pilar.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_APilar_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UFieldElement_NoRegister, (int32)VTABLE_OFFSET(APilar, IFieldElement), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APilar_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APilar>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APilar_Statics::ClassParams = {
		&APilar::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_APilar_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APilar_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APilar()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APilar_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APilar, 3300214407);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<APilar>()
	{
		return APilar::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APilar(Z_Construct_UClass_APilar, &APilar::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("APilar"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APilar);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
