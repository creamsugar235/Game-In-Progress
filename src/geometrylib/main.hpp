#pragma once
#include <algorithm>
#include <cmath>
#include <exception>
#include <string>
#include <tuple>
#include <vector>
namespace geo
{
	class Calc;
	class Line;
	class Exception;
	class Point;
	template <typename T> class Pointer;
	class Shape;
	class ConvexShape;
	class CircularShape;
	class Vector;

	enum ShapeType
	{
		RigidBody,
		StaticBody,
		KinematicBody
	};
	
	class Exception : public std::runtime_error
	{
		std::string what_message;
		public:
			Exception(std::string message) : std::runtime_error(message)
			{
			}
			const char * what()
			{
				return this->what_message.c_str();
			}
	};

	class Point
	{
		public:
			double x = 0;
			double y = 0;
			Point();
			Point(const Point& p);
			Point(Pointer<Point> p);
			Point(double x, double y);
			~Point();
			Point Clone() const;
			Point operator*(const Point& p);
			Point operator+(const Point& p);
			Point operator-(const Point& p);
			bool operator^(Line l) const;
			bool operator==(const Point& p) const;
			bool operator!=(const Point& p) const;
			bool operator<(const Point& p) const;
			bool operator>(const Point& p) const;
			Point operator()() const;
			void Move(double offsetX, double offsetY);
			int Quadrant(Pointer<Point> p) const;
			int Quadrant(const Point& p) const;
			void Rotate(Pointer<Point> p, double angle);
			void Rotate(const Point& p, double angle);
			std::string ToString() const;
			std::tuple<double, double> ToTuple() const;
	};

	class Line
	{
		private:
			double _length = 0;
			double _angle = 0;
		public:
			Line();
			Line(const Point& a, const Point& b);
			Line(Pointer<Point> a, Pointer<Point> b);
			Line(const Line& l);
			Line(Pointer<Line> l);
			~Line();
			Point a;
			Point b;
			bool operator==(const Line& l) const;
			bool operator!=(const Line& l) const;
			double angle() const;
			Point GetPointAlongLine(double distance, bool startFromA = true) const;
			double length() const;
			void Move(double offsetX, double offsetY);
			std::string ToString() const;
			std::tuple<std::tuple<double, double>, std::tuple<double, double>> ToTuple() const;
			void Rotate(const Point& pivot, double angle);
			void Rotate(Pointer<Point> pivot, double angle);
			void Update();

			
	};

	template <typename T>
	class Pointer
	{
		private:
			T * _ptr = NULL;
			size_t size = 0ULL;
			bool _shouldDelete = true;
		public:
			explicit Pointer<T>();
			explicit Pointer<T>(T * ptr, T * end);
			explicit Pointer<T>(T& val);
			~Pointer<T>();
			T& operator[](int index);
			T& operator*();
			T* operator->();
			void Set(T * ptr, T * end);
			size_t Size();
			[[nodiscard]]
			T* Switch(T * ptr);
			T* Switch(T& val);
	};

	class Shape
	{
		protected:
			double _x = 0;
			double _y = 0;
			double _rotation = 0;
		public:
			Shape();
			~Shape();
	};

	class Vector
	{
		public:
			Point start;
			Point direction;
			double magnitude;
			Vector();
			Vector(Point start, Point direction, double magnitude);
	};

	class ConvexShape : public Shape
	{
		protected:
			std::vector<Point> _points;
			std::vector<Line> _lines;
			std::vector<Vector> _vectors;
		public:
			ConvexShape();
			ConvexShape(std::vector<Point> points);
			~ConvexShape();
			double x() const;
			double y() const;
			double rotation() const;
			int _shapeType = 0;
			ConvexShape Clone();
			void AddPoint(const Point& p);
			bool IsIn(const Point& p) const;
			void Move(double offsetX, double offsetY);
			std::vector<Point> ReturnPoints() const;
			void Rotate(const Point& p, double angle);
			void Scale(double xFactor, double yFactor);
			std::string ToString() const;

	};

	class CircularShape : Shape
	{
	};

	class Calc
	{
		public:
			static double Degrees(double angle);
			static double Diagonal(double width, double height);
			static double Distance(const Point& a, const Point& b);
			static double Distance(Pointer<Point> a, Pointer<Point> b);
			static double GetAngle(const Point& a, const Point& b, const Point& c);
			static double GetAngle(Pointer<Point> a, Pointer<Point> b, Pointer<Point> c);
			static double GetAngle(double slope);
			static double GetAngle(const Point& center, const Point& point);
			static double GetAngle(Pointer<Point> center, Pointer<Point> point);
			static Point GetPointOnCircle(const Point& center, double radius, double angle);
			static Point GetPointOnCircle(Pointer<Point> center, double radius, double angle);
			static double GetSlope(const Point& a, const Point& b);
			static double GetSlope(Pointer<Point> a, Pointer<Point> b);
			static bool Intersecting(const Line& a, const Line& b, bool isInfLine = false);
			static bool Intersecting(Pointer<Line> a, Pointer<Line> b, bool isInfLine = false);
			static Point PointOfIntersect(const Line& a, const Line& b, bool isInfLine = false);
			static Point PointOfIntersect(Pointer<Line> a, Pointer<Line> b, bool isInfLine = false);
	};

	const Point Origin = Point(0, 0);
	const Point Infinity = Point(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());
}
#include "Pointer.inl"