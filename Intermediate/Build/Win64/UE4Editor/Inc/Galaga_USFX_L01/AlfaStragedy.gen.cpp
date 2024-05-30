// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/AlfaStragedy.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAlfaStragedy() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AAlfaStragedy_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AAlfaStragedy();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UFieldStragedy_NoRegister();
// End Cross Module References
	void AAlfaStragedy::StaticRegisterNativesAAlfaStragedy()
	{
	}
	UClass* Z_Construct_UClass_AAlfaStragedy_NoRegister()
	{
		return AAlfaStragedy::StaticClass();
	}
	struct Z_Construct_UClass_AAlfaStragedy_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAlfaStragedy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlfaStragedy_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AlfaStragedy.h" },
		{ "ModuleRelativePath", "AlfaStragedy.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AAlfaStragedy_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UFieldStragedy_NoRegister, (int32)VTABLE_OFFSET(AAlfaStragedy, IFieldStragedy), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAlfaStragedy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAlfaStragedy>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAlfaStragedy_Statics::ClassParams = {
		&AAlfaStragedy::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AAlfaStragedy_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAlfaStragedy_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAlfaStragedy()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAlfaStragedy_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAlfaStragedy, 539445312);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AAlfaStragedy>()
	{
		return AAlfaStragedy::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAlfaStragedy(Z_Construct_UClass_AAlfaStragedy, &AAlfaStragedy::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AAlfaStragedy"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAlfaStragedy);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
