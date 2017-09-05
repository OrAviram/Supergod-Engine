#pragma once

#include "IVector.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Represents a 2-component mathematical vector.
	/// </summary>
	struct SUPERGOD_API Vector2D final : public IVector<Vector2D>
	{
		union
		{
			struct { float x, y; };
			float components[2];
		};
		
		/// <summary>Creates a new 2D vector and initializes both of its components to 0.</summary>
		Vector2D();

		/// <summary>Creates a new 2D vector and initializes its components to x and y.</summary>
		explicit Vector2D(const float& x, const float& y);

		#pragma region Magnitude, squared magnitude and normalization.
		/// <summary>
		/// Gets the magnitude (length) of this vector.
		/// </summary>
		float Magnitude() const override;
		
		/// <summary>
		/// Gets the squared magnitude (length) of this vector. This is faster than squaring the magnitude.
		/// </summary>
		float SqrMagnitude() const override;
		
		/// <summary>
		/// Gets a unit vector pointing in the same direction of this vector.
		/// </summary>
		Vector2D Normalized() const override;
		#pragma endregion

		#pragma region Multiplication (Dot, Multiply, and the operators).
		/// <summary>
		/// Gets the dot product of this and other.
		/// </summary>
		float Dot(const Vector2D& other) const override;

		/// <summary>
		/// Multiplies this and other component-wise.
		/// </summary>
		Vector2D Multiply(const Vector2D& other) const override;

		/// <summary>
		/// Multiplies every component of this by scalar.
		/// </summary>
		Vector2D Multiply(const float& scalar) const override;

		/// <summary>
		/// Multiplies this and other component-wise.
		/// </summary>
		Vector2D operator*(const Vector2D& other) const;

		/// <summary>
		/// Multiplies every component of this by other.
		/// </summary>
		Vector2D operator*(const float& scalar) const;
		#pragma endregion

		#pragma region Those methods are here just so it will compile. I will organize and implement them later.
		bool Equals(const Vector2D & other) const override;

		bool CloseEnough(const Vector2D & other, const float & threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD) const override;

		Vector2D Abs() const override;

		Vector2D Clamp(const Vector2D & min, const Vector2D & max) const override;

		Vector2D Add(const Vector2D & other) const override;

		Vector2D Subtract(const Vector2D & other) const override;

		Vector2D Negated() const override;
		Vector2D Divide(const float & scalar) const override;

		const float & BiggestComponent() const override;

		const float & SmallestComponent() const override;

		bool ContainsComponent(std::function<void(const float&)> test) const override;

		Vector2D ClampComponents(const float & min, const float & max) const override;
		#pragma endregion
	};
} }