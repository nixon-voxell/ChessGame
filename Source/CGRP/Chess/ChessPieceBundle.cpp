// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessPieceBundle.h"

FChessPiece* FChessPieceBundle::GetChessPiece(int32 Index)
{
	return this->ChessPieces[Index];
}

APieceItem* FChessPieceBundle::GetPieceItem(int32 Index)
{
	return this->PieceItems[Index];
}

void FChessPieceBundle::Initialize()
{
	// Initialize array items
	this->PieceItems[0] = NULL;
	this->PieceItems[1] = this->Pawn.Item.GetDefaultObject();
	this->PieceItems[2] = this->Rook.Item.GetDefaultObject();
	this->PieceItems[3] = this->Knight.Item.GetDefaultObject();
	this->PieceItems[4] = this->BishopPiece.Item.GetDefaultObject();
	this->PieceItems[5] = this->QueenPiece.Item.GetDefaultObject();
	this->PieceItems[6] = this->KingPiece.Item.GetDefaultObject();

	this->ChessPieces[0] = NULL;
	this->ChessPieces[1] = &this->Pawn;
	this->ChessPieces[2] = &this->Rook;
	this->ChessPieces[3] = &this->Knight;
	this->ChessPieces[4] = &this->BishopPiece;
	this->ChessPieces[5] = &this->QueenPiece;
	this->ChessPieces[6] = &this->KingPiece;
}

FChessPieceBundle::FChessPieceBundle()
{
}

FChessPieceBundle::~FChessPieceBundle()
{
}
