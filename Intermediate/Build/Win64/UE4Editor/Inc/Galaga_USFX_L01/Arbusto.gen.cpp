// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/Arbusto.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeArbusto() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AArbusto_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AArbusto();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UFieldElement_NoRegister();
// End Cross Module References
	void AArbusto::StaticRegisterNativesAArbusto()
	{
	}
	UClass* Z_Construct_UClass_AArbusto_NoRegister()
	{
		return AArbusto::StaticClass();
	}
	struct Z_Construct_UClass_AArbusto_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AArbusto_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AArbusto_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Arbusto.h" },
		{ "ModuleRelativePath", "Arbusto.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AArbusto_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UFieldElement_NoRegister, (int32)VTABLE_OFFSET(AArbusto, IFieldElement), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AArbusto_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AArbusto>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AArbusto_Statics::ClassParams = {
		&AArbusto::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AArbusto_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AArbusto_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AArbusto()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AArbusto_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AArbusto, 2831547306);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AArbusto>()
	{
		return AArbusto::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AArbusto(Z_Construct_UClass_AArbusto, &AArbusto::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AArbusto"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AArbusto);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
