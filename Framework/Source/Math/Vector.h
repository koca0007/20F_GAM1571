#pragma once

namespace fw
{
	inline bool fequal(float a, float b, float epsilon = 0.000001f)
	{
		return (fabsf(a - b) < epsilon);
	}
			
	
	class Vector2
	{
	public:
		Vector2() { x = 0; y = 0; }
		Vector2(float ax, float ay) { x = ax; y = ay; }

		void SetX(float o) { x = o; }
		void SetY(float o) { y = o; }
		void Set(Vector2 o) { x = o.x, y = o.y; }

		float GetPositionX() { return x; }
		float GetPositionY() { return y; }

		Vector2 operator+(float o) const { return Vector2(x + o, y + o); }
		Vector2 operator-(float o) const { return Vector2(x - o, y - o); }
		Vector2 operator*(float o) const { return Vector2(x * o, y * o); }
		Vector2 operator/(float o) const { return Vector2(x / o, y / o); }
		Vector2 operator-() const { return Vector2(-x, -y); }

		Vector2 operator+=(float o) { return Vector2(x += o, y += o); }
		Vector2 operator-=(float o) { return Vector2(x -= o, y -= o); }
		Vector2 operator*=(float o) { return Vector2(x *= o, y *= o); }
		Vector2 operator/=(float o) { return Vector2(x /= o, y /= o); }

		Vector2 operator+(const Vector2& other) const { return Vector2(x + other.x, y + other.y); }
		Vector2 operator-(const Vector2& other) const { return Vector2(x - other.x, y - other.y); }
		Vector2 operator*(const Vector2& other) const { return Vector2(x * other.x, y * other.y); }
		Vector2 operator/(const Vector2& other) const { return Vector2(x / other.x, y / other.y); }

		Vector2 operator+=(const Vector2& o) { x += o.x; y += o.y; return *this; }
		Vector2 operator-=(const Vector2& o) { x -= o.x; y -= o.y; return *this; }
		Vector2 operator*=(const Vector2& o) { x *= o.x; y *= o.y; return *this; }
		Vector2 operator/=(const Vector2& o) { x /= o.x; y /= o.y; return *this; }

		bool operator==(const Vector2& aVector2) const	{ return (fequal(x, aVector2.x) && fequal(y, aVector2.y)); }
		bool operator!=(const Vector2& aVector2) const	{ return x != aVector2.x || y != aVector2.y; }
		bool operator<(const Vector2&  aVector2) const	{ return (x == aVector2.x) ? (y < aVector2.y) : (x < aVector2.x); }
		bool operator<=(const Vector2& aVector2) const	{ return (x == aVector2.x) ? (y <= aVector2.y) : (x <= aVector2.x); }
		bool operator>(const Vector2&  aVector2) const	{ return (x == aVector2.x) ? (y > aVector2.y) : (x > aVector2.x); }
		bool operator>=(const Vector2& aVector2) const	{ return (x == aVector2.x) ? (y >= aVector2.y) : (x >= aVector2.x); }


		float Length() { return sqrtf(SquaredLength()); }
		float SquaredLength() { return x * x + y * y; }

		void Normalize() {
			float length = SquaredLength();
			if (length != 0)
			{
				length = sqrtf(length);
				x /= length;
				y /= length;
			}
		}

		Vector2 Normalized()
		{
			Vector2 vec2 = Vector2(x, y);
			vec2.Normalize();
			return vec2;
		}

		float Distance(const Vector2& o) { return sqrtf(SquaredDistance(o)); }

		float SquaredDistance(const Vector2& o)
		{
			return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y);
		}

		float DotProduct(const Vector2& o) { return x * o.x + y * o.y; }

		float operator[](int i) { assert(i >= 0 && i <= 1); return *(&x + 1); }

	public:
		float x = 0;
		float y = 0;
	};

	inline Vector2 operator+(float scalar, const Vector2& vector) { return Vector2(scalar + vector.x, scalar + vector.y); }
	inline Vector2 operator-(float scalar, const Vector2& vector) { return Vector2(scalar - vector.x, scalar - vector.y); }
	inline Vector2 operator*(float scalar, const Vector2& vector) { return Vector2(scalar * vector.x, scalar * vector.y); }
	inline Vector2 operator/(float scalar, const Vector2& vector) { return Vector2(scalar / vector.x, scalar / vector.y); }

	
	class iVector2
	{
	public:
		iVector2() { x = 0; y = 0; }
		iVector2(int nx, int ny) { x = nx; y = ny; }

		void Set(int nx, int ny) { x = nx; y = ny; }

	public:
		int x;
		int y;
	};

	class Vector4
	{
	public:
		Vector4() { x = 0; y = 0; z = 0; w = 0; }
		Vector4(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }

		static const Vector4 Green()	 { return Vector4(0.0f, 1.0f, 0.0f, 1.0f); }
		static const Vector4 Red()		 { return Vector4(1.0f, 0.0f, 0.0f, 1.0f); }
		static const Vector4 Blue()		 { return Vector4(0.0f, 0.0f, 1.0f, 1.0f); }
		static const Vector4 White()	 { return Vector4(1.0f, 1.0f, 1.0f, 1.0f); }
		static const Vector4 Black()	 { return Vector4(0.0f, 0.0f, 0.0f, 1.0f); }
		static const Vector4 Orange()	 { return Vector4(1.0f, 0.4f, 0.0f, 1.0f); }
		static const Vector4 Yellow()	 { return Vector4(1.0f, 1.0f, 0.0f, 1.0f); }
		static const Vector4 Purple()	 { return Vector4(0.5f, 0.0f, 0.5f, 1.0f); }
		static const Vector4 Grey()		 { return Vector4(0.3f, 0.3f, 0.3f, 1.0f); }
		static const Vector4 Indigo()	 { return Vector4(0.3f, 0.0f, 0.5f, 1.0f); }
		static const Vector4 DarkGreen() { return Vector4(0.0f, 0.7f, 0.0f, 1.0f); }

	public:
		union
		{
			float x;
			float r;
		};
		union
		{
			float y;
			float g;
		};
		union
		{
			float z;
			float b;
		};
		union
		{
			float w;
			float a;
		};
	};
}