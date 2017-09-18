#pragma once

#include "IVector.h"
#include "Vector2D.h"
#include "Vector3D.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Represents a 4-component mathematical vector.
	/// </summary>
	struct SUPERGOD_API Vector4D final : public IVector<Vector4D>
	{
		#pragma region Presets for common vectors.
		/// <summary>(0, 0, 0, 0)</summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector4D, Zero, (0, 0, 0, 0))

		/// <summary>(1, 1, 1, 1)</summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector4D, One, (1, 1, 1, 1))

		/// <summary>(1, 0, 0, 0)</summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector4D, UnitX, (1, 0, 0, 0))

		/// <summary>(0, 1, 0, 0)</summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector4D, UnitY, (0, 1, 0, 0))

		/// <summary>(0, 0, 1, 0)</summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector4D, UnitZ, (0, 0, 1, 0))

		/// <summary>(0, 0, 0, 1)</summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector4D, UnitW, (0, 0, 0, 1))
		#pragma endregion

		union
		{
			struct { float x, y, z, w; };
			float components[4];
		};
		
		/// <summary>Initializes a new Vector4D with all of its components set to 0.</summary>
		Vector4D();

		/// <summary>Initializes a new Vector4D for with an x, a y, a z, and a w.</summary>
		explicit Vector4D(const float& x, const float& y, const float& z, const float& w);

		/// <summary>Initializes a new Vector4D with a vector for x and y and a vector for z and w.</summary>
		explicit Vector4D(const Vector2D& xy, const Vector2D& zw);

		/// <summary>Initializes a new Vector4D with a vector for x, y and z and a const float& for w.</summary>
		explicit Vector4D(const Vector3D& xyz, const float& w);

		/// <summary>Initializes a new Vector4D with a const float& for x and a vector for y, z and w.</summary>
		explicit Vector4D(const float& x, const Vector3D& yzw);

		/// <summary>Initializes a new Vector4D with a const float& for x, y, and a vector for z and w.</summary>
		explicit Vector4D(const float& x, const float& y, const Vector2D& zw);

		/// <summary>Initializes a new Vector4D with a const float& for x, a vector for y and z, and a const float& for w.</summary>
		explicit Vector4D(const float& x, const Vector2D& yz, const float& w);

		/// <summary>Initializes a new Vector4D with a vector for x and y and floats for z and w.</summary>
		explicit Vector4D(const Vector2D& xy, const float& z, const float& w);

		/// <summary>
		/// Gets a reference to a component at the index of index.
		/// </summary>
		/// <param name="index">The index of the component (0, 1, 2 or 3).</param>
		inline float& operator[](int index)
		{
			return components[index];
		}

		/// <summary>
		/// Gets a reference to a component at the index of index.
		/// </summary>
		/// <param name="index">The index of the component (0, 1, 2 or 3).</param>
		inline const float& operator[](int index) const
		{
			return components[index];
		}

        #pragma region Specific Vector3D Axes.
        // X y and z combinations:
        inline Vector3D YXZ() const { return Vector3D(y, x, z); }
        inline Vector3D YZX() const { return Vector3D(y, z, x); }

        inline Vector3D ZXY() const { return Vector3D(z, x, y); }
        inline Vector3D XZY() const { return Vector3D(x, z, y); }

        inline Vector3D ZYX() const { return Vector3D(z, y, x); }
        inline Vector3D XYZ() const { return Vector3D(x, y, z); }

        // Y z and w combinations:
        inline Vector3D YZW() const { return Vector3D(y, z, w); }
        inline Vector3D YWZ() const { return Vector3D(y, w, z); }

        inline Vector3D ZYW() const { return Vector3D(z, y, w); }
        inline Vector3D WYZ() const { return Vector3D(w, y, z); }

        inline Vector3D ZWY() const { return Vector3D(z, w, y); }
        inline Vector3D WZY() const { return Vector3D(w, z, y); }

        // X z and w combinations:
        inline Vector3D XZW() const { return Vector3D(x, z, w); }
        inline Vector3D XWZ() const { return Vector3D(x, w, z); }

        inline Vector3D ZXW() const { return Vector3D(z, x, w); }
        inline Vector3D WXZ() const { return Vector3D(w, x, z); }

        inline Vector3D ZWX() const { return Vector3D(z, w, x); }
        inline Vector3D WZX() const { return Vector3D(w, z, x); }

        // Y w and x combinations:
        inline Vector3D YWX() const { return Vector3D(y, w, x); }
        inline Vector3D YXW() const { return Vector3D(y, x, w); }

        inline Vector3D XYW() const { return Vector3D(x, y, w); }
        inline Vector3D WYX() const { return Vector3D(w, y, x); }

        inline Vector3D XWY() const { return Vector3D(x, w, y); }
        inline Vector3D WXY() const { return Vector3D(w, x, y); }
        #pragma endregion

        #pragma region Specific Vector2D Axes.
        inline Vector2D XY() const { return Vector2D(x, y); }
        inline Vector2D YX() const { return Vector2D(y, x); }

        inline Vector2D XZ() const { return Vector2D(x, z); }
        inline Vector2D ZX() const { return Vector2D(z, x); }

        inline Vector2D XW() const { return Vector2D(x, w); }
        inline Vector2D WX() const { return Vector2D(w, x); }

        inline Vector2D YZ() const { return Vector2D(y, z); }
        inline Vector2D ZY() const { return Vector2D(z, y); }

        inline Vector2D YW() const { return Vector2D(y, w); }
        inline Vector2D WY() const { return Vector2D(w, y); }

        inline Vector2D ZW() const { return Vector2D(z, w); }
        inline Vector2D WZ() const { return Vector2D(w, z); }
        #pragma endregion

		#pragma region Comparison methods (Equals, ContainsComponent and CloseEnough)
		/// <summary>
		/// Is every component of this same as its corresponding component in other?
		/// </summary>
		bool Equals(const Vector4D& other) const override;

		/// <summary>
		/// Is every component of this close enough to its corresponding component in other with the threshold of threshold?<para/>
		/// See SupergodEngine::Math::Smath::CloseEnough.
		/// </summary>
		/// <param name="threshold">The threshold for each component to be considered close enough.</param>
		bool CloseEnough(const Vector4D& other, const float& threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD) const override;

		/// <summary>
		/// Does any component pass test?
		/// </summary>
		/// <param name="test">The test to run for each component.</param>
		bool ContainsComponent(const std::function<bool(const float&)>& test) const override;
		#pragma endregion

		#pragma region Addition, subtraction and negation.
		/// <summary>
		/// Adds every component of this with its corresponding component in other.
		/// </summary>
		Vector4D Add(const Vector4D& other) const override;

		/// <summary>
		/// Subtracts every component of other from its corresponding component in this.
		/// </summary>
		Vector4D Subtract(const Vector4D& other) const override;

		/// <summary>
		/// Negates every component of this.
		/// </summary>
		Vector4D Negated() const override;
		#pragma endregion

		#pragma region Multiplication (Dot and Multiply).
		/// <summary>
		/// Gets the dot product of this and other.
		/// </summary>
		float Dot(const Vector4D& other) const override;

		/// <summary>
		/// Multiplies this and other component-wise.
		/// </summary>
		Vector4D Multiply(const Vector4D& other) const override;

		/// <summary>
		/// Multiplies every component of this by scalar.
		/// </summary>
		Vector4D Multiply(const float& scalar) const override;
		#pragma endregion

		#pragma region Division.
		/// <summary>
		/// Divides every component of this by scalar.
		/// </summary>
		Vector4D Divide(const float& scalar) const override;

		/// <summary>
		/// Divides every component of this by its corresponding component in scalar.
		/// </summary>
		Vector4D Divide(const Vector4D& other) const override;
		#pragma endregion

		#pragma region BiggestComponent/BiggestComponent.
		/// <summary>
		/// Gets a reference to the biggest component in the vector.
		/// </summary>
		float& BiggestComponent() override;

		/// <summary>
		/// Gets a reference to the smallest component in the vector.
		/// </summary>
		float& SmallestComponent() override;

		/// <summary>
		/// Gets a reference to the biggest component in the vector.
		/// </summary>
		const float& BiggestComponent() const override;

		/// <summary>
		/// Gets a reference to the smallest component in the vector.
		/// </summary>
		const float& SmallestComponent() const override;
		#pragma endregion

		#pragma region Clamping methods.
		/// <summary>
		/// Gets a vector where all of its components are the absolute value of their corresponding component in this.
		/// </summary>
		/// <returns></returns>
		Vector4D Abs() const override;

		/// <summary>
		/// Clamps every component of this so it's never smaller than its corresponding component in min and never bigger than its corresponding component in max.
		/// </summary>
		Vector4D Clamp(const Vector4D& min, const Vector4D& max) const override;

		/// <summary>
		/// Clamps every component of this so it's never smaller than min and never bigger than max.
		/// </summary>
		Vector4D ClampComponents(const float& min, const float& max) const override;
		#pragma endregion
	};
} }