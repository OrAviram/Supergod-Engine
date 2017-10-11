#pragma once

#include "Common/CommonDefines.h"
#include "../Interfaces/ArithmeticInterfaces.h"
#include "../Interfaces/ISupergodEquatable.h"
#include "../Interfaces/ILerpable.h"

// I want to keep the virtual methods here for now, in case I will use it again...even though I doubt it will happen.

namespace SupergodCore { namespace Math
{
	template<class ...> struct MatrixBase;

	/// <summary>
	/// The base struct for IMatrix{TMatrix, TVector}. This is only used when trying to reference a matrix of a generic type.<para/>
	/// When deriving, use IMatrix{TMatrix, TVector}.
	/// </summary>
	template<class T>
	struct SUPERGOD_API_CLASS MatrixBase<T> : public ISupergodEquatable<T>, public ILerpable<T>, public ISubtractable<T>, public IMultipliable<T>, public INegatable<T>, public IScalarDividable<T>
	{
		//virtual const float& operator[](int index) const = 0;
		//virtual float& operator[](int index) = 0;

		//virtual const float& operator() (int row, int column) const = 0;
		//virtual float& operator() (int row, int column) = 0;

		//virtual T MultiplyComponentWise(const T& other) const = 0;

		//virtual T Transposed() const = 0;
		//virtual T Minor() const = 0;
		//virtual T Cofactor() const = 0;

		//virtual float Determinant() const = 0;
		//virtual float Trace() const = 0;

		//virtual T ClampElements(float min, float max) const = 0;

		/// <summary>
		/// Gets the transpose of the cofactor matrix.
		/// </summary>
		/// <returns></returns>
		inline T Adjugate() const
		{
			return TEMPLATED_INTERFACE_THIS.Cofactor().Transposed();
		}

		/// <summary>
		/// Gets the multiplicative inverse of this matrix.
		/// </summary>
		/// <returns></returns>
		inline T Inverted() const
		{
			return TEMPLATED_INTERFACE_THIS.Adjugate() / TEMPLATED_INTERFACE_THIS.Determinant();
		}
		
		/// <summary>
		/// Multiplies every element of matrix by scalar.
		/// </summary>
		inline friend T operator*(float scalar, const T& matrix)
		{
			return matrix * scalar;
		}
	};

	/// <summary>
	/// A struct all matrices can derive from.<para/>
	/// TVector is the type of the vector for rows and columns.
	/// </summary>
	template<class TMatrix, class TVector>
	struct SUPERGOD_API_CLASS MatrixBase<TMatrix, TVector> : public MatrixBase<TMatrix>
	{
		//virtual TVector GetRow(int index) const = 0;
		//virtual TVector SetRow(int index, const TVector& value) = 0;

		//virtual const TVector& GetColumn(int index) const = 0;
		//virtual TVector& GetColumn(int index) = 0;

		//virtual TVector Multiply(const TVector& vector) const = 0;
		//virtual TMatrix ClampRows(const TVector& min, const TVector& max) const = 0;
		//virtual TMatrix ClampColumns(const TVector& min, const TVector& max) const = 0;

		/// <summary>
		/// Multiplies vector by this (where vector is a row vector). This will NOT transform vector.
		/// </summary>
		inline friend TVector operator*(const TVector& vector, const TMatrix& matrix)
		{
			return matrix.Transposed().Multiply(vector);
		}

		/// <summary>
		/// Multiplies vector by this (where vector is a row vector). This will NOT transform vector.
		/// </summary>
		inline friend TVector operator*(const TMatrix& matrix, const TVector& vector)
		{
			return matrix.Multiply(vector);
		}
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
		inline TMatrix ClampRows(const TMatrix& matrix, const TVector& min, const TVector& max)
		{
			return matrix.ClampRows(min, max);
		}

		/// <summary>
		/// Calls the ClampColumns method on matrix and passes min as the minimum and max as the maximum.
		/// </summary>
		template<class TMatrix, class TVector>
		inline TMatrix ClampColumns(const TMatrix& matrix, const TVector& min, const TVector& max)
		{
			return matrix.ClampColumns(min, max);
		}

		/// <summary>
		/// Gest the Transposed property of matrix.
		/// </summary>
		template<class T>
		inline T Transpose(const T& matrix)
		{
			return matrix.Transposed();
		}

		/// <summary>
		/// Gest the Cofactor property of matrix.
		/// </summary>
		template<class T>
		inline T Cofactor(const T& matrix)
		{
			return matrix.Cofactor();
		}

		/// <summary>
		/// Gets the determinant of matrix.
		/// </summary>
		template<class T>
		inline float Det(const T& matrix)
		{
			return matrix.Determinant();
		}

		/// <summary>
		/// Gets the trace of matrix.
		/// </summary>
		template<class T>
		inline T Tr(const T& matrix)
		{
			return matrix.Trace();
		}

		/// <summary>
		/// Calls teh ClampAxes method of vector and passes min as the minimum and max as the maximum.
		/// </summary>
		template<class T>
		inline T ClampElements(const T& matrix, float min, float max)
		{
			return matrix.ClampElements(min, max);
		}

		/// <summary>
		/// Calls the Abs method of matrix.
		/// </summary>
		template<class T>
		inline T Abs(const T& matrix)
		{
			return matrix.Abs();
		}

		/// <summary>
		/// Gets the adjugate matrix of matrix.
		/// Same as the transpose of the cofactor matrix.
		/// </summary>
		template<class T>
		inline T Adjugate(const T& matrix)
		{
			return matrix.Adjugate();
		}

		/// <summary>
		/// Gets the matrix that when multiplies matrix will result in the identity matrix.
		/// Same case when multiplying matrix by the resulting matrix from this method.
		/// </summary>
		template<class T>
		inline T Invert(const T& matrix)
		{
			return matrix.Inverted();
		}

		/// <summary>
		/// Multiplies vector by this (where vector is a row vector). This will NOT transform vector.
		/// </summary>
		template<class TVector, class TMatrix>
		inline TVector Multiply(const TVector& vector, const TMatrix& matrix)
		{
			return vector * matrix;
		}
	}
} }