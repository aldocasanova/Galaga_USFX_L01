// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/DeltaStragedy.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeltaStragedy() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ADeltaStragedy_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ADeltaStragedy();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UFieldStragedy_NoRegister();
// End Cross Module References
	void ADeltaStragedy::StaticRegisterNativesADeltaStragedy()
	{
	}
	UClass* Z_Construct_UClass_ADeltaStragedy_NoRegister()
	{
		return ADeltaStragedy::StaticClass();
	}
	struct Z_Construct_UClass_ADeltaStragedy_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADeltaStragedy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADeltaStragedy_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DeltaStragedy.h" },
		{ "ModuleRelativePath", "DeltaStragedy.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ADeltaStragedy_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UFieldStragedy_NoRegister, (int32)VTABLE_OFFSET(ADeltaStragedy, IFieldStragedy), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADeltaStragedy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADeltaStragedy>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ADeltaStragedy_Statics::ClassParams = {
		&ADeltaStragedy::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ADeltaStragedy_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADeltaStragedy_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADeltaStragedy()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ADeltaStragedy_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADeltaStragedy, 3086520443);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ADeltaStragedy>()
	{
		return ADeltaStragedy::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADeltaStragedy(Z_Construct_UClass_ADeltaStragedy, &ADeltaStragedy::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ADeltaStragedy"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADeltaStragedy);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
