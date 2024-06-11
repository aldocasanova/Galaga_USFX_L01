// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/Coliseo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeColiseo() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AColiseo_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AColiseo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UFieldElement_NoRegister();
// End Cross Module References
	void AColiseo::StaticRegisterNativesAColiseo()
	{
	}
	UClass* Z_Construct_UClass_AColiseo_NoRegister()
	{
		return AColiseo::StaticClass();
	}
	struct Z_Construct_UClass_AColiseo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AColiseo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AColiseo_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Coliseo.h" },
		{ "ModuleRelativePath", "Coliseo.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AColiseo_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UFieldElement_NoRegister, (int32)VTABLE_OFFSET(AColiseo, IFieldElement), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AColiseo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AColiseo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AColiseo_Statics::ClassParams = {
		&AColiseo::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AColiseo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AColiseo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AColiseo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AColiseo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AColiseo, 4189290161);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AColiseo>()
	{
		return AColiseo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AColiseo(Z_Construct_UClass_AColiseo, &AColiseo::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AColiseo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AColiseo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
