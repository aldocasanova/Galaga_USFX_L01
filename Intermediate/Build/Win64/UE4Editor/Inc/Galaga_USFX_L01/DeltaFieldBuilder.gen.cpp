// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/DeltaFieldBuilder.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeltaFieldBuilder() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ADeltaFieldBuilder_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ADeltaFieldBuilder();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UIGalacticFieldBuilder_NoRegister();
// End Cross Module References
	void ADeltaFieldBuilder::StaticRegisterNativesADeltaFieldBuilder()
	{
	}
	UClass* Z_Construct_UClass_ADeltaFieldBuilder_NoRegister()
	{
		return ADeltaFieldBuilder::StaticClass();
	}
	struct Z_Construct_UClass_ADeltaFieldBuilder_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADeltaFieldBuilder_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADeltaFieldBuilder_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DeltaFieldBuilder.h" },
		{ "ModuleRelativePath", "DeltaFieldBuilder.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ADeltaFieldBuilder_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UIGalacticFieldBuilder_NoRegister, (int32)VTABLE_OFFSET(ADeltaFieldBuilder, IIGalacticFieldBuilder), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADeltaFieldBuilder_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADeltaFieldBuilder>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ADeltaFieldBuilder_Statics::ClassParams = {
		&ADeltaFieldBuilder::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ADeltaFieldBuilder_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADeltaFieldBuilder_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADeltaFieldBuilder()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ADeltaFieldBuilder_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADeltaFieldBuilder, 1433643520);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ADeltaFieldBuilder>()
	{
		return ADeltaFieldBuilder::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADeltaFieldBuilder(Z_Construct_UClass_ADeltaFieldBuilder, &ADeltaFieldBuilder::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ADeltaFieldBuilder"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADeltaFieldBuilder);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
