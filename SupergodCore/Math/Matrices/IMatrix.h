#pragma once

#include "Common/CommonDefines.h"
#include "../Interfaces/ArithmeticInterfaces.h"
#include "../Interfaces/ISupergodEquatable.h"
#include "../Interfaces/IAbsolutable.h"
#include "../Interfaces/ILerpable.h"
#include "../Interfaces/IClampable.h"

namespace SupergodCore { namespace Math
{
	template<class ...> interface IMatrix;

	/// <summary>
	/// The base interface for IMatrix{TMatrix, TVector}. This is only used when trying to reference a matrix of a generic type.<para/>
	/// When implementing, use IMatrix{TMatrix, TVector}.
	/// </summary>
	template<class T>
	interface SUPERGOD_API IMatrix<T> : public ISupergodEquatable<T>, public IAbsolutable<T>, public ILerpable<T>, public IClampable<T>, public ISubtractable<T>, public IMultipliable<T>, public INegatable<T>, public IScalarDividable<T>
	{
		virtual const float& operator[](int index) const = 0;
		virtual float& operator[](int index) = 0;

		virtual const float& operator() (int row, int column) const = 0;
		virtual float& operator() (int row, int column) = 0;

		virtual T MultiplyComponentWise(const T& other) const = 0;

		virtual T Transposed() const = 0;
		virtual T Minor() const = 0;
		virtual T Cofactor() const = 0;

		virtual float Determinant() const = 0;
		virtual float Trace() const = 0;

		virtual T ClampElements(float min, float max) const = 0;

		/// <summary>
		/// Gets the transpose of the cofactor matrix.
		/// </summary>
		/// <returns></returns>
		inline T Adjugate() const
		{
			return Cofactor().Transposed();
		}

		/// <summary>
		/// Gets the multiplicative inverse of this matrix.
		/// </summary>
		/// <returns></returns>
		inline T Inverted() const
		{
			return 1 / Determinant() * Adjugate();
		}
	};

	/// <summary>
	/// An interface all matrices can implement.<para/>
	/// TVector is the type of the vector for rows and columns.
	/// </summary>
	template<class TMatrix, class TVector>
	interface SUPERGOD_API IMatrix<TMatrix, TVector> : public IMatrix<TMatrix>
	{
		const TVector& GetRow(int index) const = 0;
		TVector& GetRow(int index) = 0;

		virtual const TVector& GetColumn(int index) const = 0;
		virtual TVector& GetColumn(int index) = 0;

		virtual const TVector& GetRow(int index) const = 0;
		virtual TVector& GetRow(int index) = 0;

		virtual TVector Multiply(const TVector& vector) const = 0;
		virtual TVector ClampRows(const TVector& min, const TVector& max) const = 0;
		virtual TVector ClampColumns(const TVector& min, const TVector& max) const = 0;
	};

	/// <summary>
	/// Namespace that calls functions from IMatrix.
	/// </summary>
	namespace Matrix
	{
		/// <summary>
		/// Calls the ClampRows method on matrix and passes min as the minimum and max as the maximum.
		/// </summary>
		template<class TMatrix, class TVector>
		inline TMatrix ClampRows(const IMatrix<TMatrix, TVector>& matrix, const TVector& min, const TVector& max)
		{
			return matrix.ClampRows(min, max);
		}

		/// <summary>
		/// Calls the ClampColumns method on matrix and passes min as the minimum and max as the maximum.
		/// </summary>
		template<class TMatrix, class TVector>
		inline TMatrix ClampColumns(const IMatrix<TMatrix, TVector>& matrix, const TVector& min, const TVector& max)
		{
			return matrix.ClampColumns(min, max);
		}

		/// <summary>
		/// Gest the Transposed property of matrix.
		/// </summary>
		template<class T>
		inline T Transpose(const IMatrix<T>& matrix)
		{
			return matrix.Transposed();
		}

		/// <summary>
		/// Gest the Cofactor property of matrix.
		/// </summary>
		template<class T>
		inline T Cofactor(const IMatrix<T>& matrix)
		{
			return matrix.Cofactor();
		}

		/// <summary>
		/// Gets the determinant of matrix.
		/// </summary>
		template<class T>
		inline T Det(const IMatrix<T>& matrix)
		{
			return matrix.Determinant();
		}

		/// <summary>
		/// Gets the trace of matrix.
		/// </summary>
		template<class T>
		inline T Tr(const IMatrix<T>& matrix)
		{
			return matrix.Trace();
		}

		/// <summary>
		/// Calls teh ClampAxes method of vector and passes min as the minimum and max as the maximum.
		/// </summary>
		template<class T>
		inline T ClampElements(const IMatrix<T>& matrix, float min, float max)
		{
			return matrix.ClampElements(min, max);
		}

		/// <summary>
		/// Calls the Abs method of matrix.
		/// </summary>
		template<class T>
		inline T Abs(const IMatrix<T>& matrix)
		{
			return matrix.Abs();
		}

		/// <summary>
		/// Gets the adjugate matrix of matrix.
		/// Same as the transpose of the cofactor matrix.
		/// </summary>
		template<class T>
		inline T Adjugate(const IMatrix<T>& matrix)
		{
			return matrix.Adjugate();
		}

		/// <summary>
		/// Gets the matrix that when multiplies matrix will result in the identity matrix.
		/// Same case when multiplying matrix by the resulting matrix from this method.
		/// </summary>
		template<class T>
		inline T Invert(const IMatrix<T>& matrix)
		{
			return matrix.Inverted();
		}
	}
} }