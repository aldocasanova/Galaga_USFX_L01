// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/NaveNodrizaState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNaveNodrizaState() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UNaveNodrizaState_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UNaveNodrizaState();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void UNaveNodrizaState::StaticRegisterNativesUNaveNodrizaState()
	{
	}
	UClass* Z_Construct_UClass_UNaveNodrizaState_NoRegister()
	{
		return UNaveNodrizaState::StaticClass();
	}
	struct Z_Construct_UClass_UNaveNodrizaState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNaveNodrizaState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNaveNodrizaState_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "NaveNodrizaState.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNaveNodrizaState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<INaveNodrizaState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UNaveNodrizaState_Statics::ClassParams = {
		&UNaveNodrizaState::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UNaveNodrizaState_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UNaveNodrizaState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UNaveNodrizaState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UNaveNodrizaState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UNaveNodrizaState, 3611604063);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<UNaveNodrizaState>()
	{
		return UNaveNodrizaState::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNaveNodrizaState(Z_Construct_UClass_UNaveNodrizaState, &UNaveNodrizaState::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("UNaveNodrizaState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNaveNodrizaState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
