#ifndef CALCULATERECT_H
#define CALCULATERECT_H

#include <QPointF>
#include <QtMath>
#include "shapesutils.h"

/* get a rect by diagPoints */
QRect   diagPointsRect(DiagPoints diagPoints);

/* judge whether the point1 is on the point2 or not */
bool    pointClickIn(QPointF point2, QPointF point1, int padding = 4);

/* judge whether the point3 is on the segment*/
bool    pointOnLine(QPointF point1, QPointF point2, QPointF point3);

/* To determine whether a point on the rectangle*/
bool    pointOnRect(DiagPoints diagPoints, QPointF pos);

/* get the point who splid a distance on a line */
QPointF  pointSplid(QPointF point1, QPointF point2, qreal padding);

/* get the rotate point by four points in a rectangle*/
QPointF  getRotatePoint(QPointF point1, QPointF point2,
                             QPointF point3, QPointF point4);

/* get the four points from a rectangle which isn't rotated!*/
FourPoints  fourPointsOnRect(DiagPoints diagPoints);

/* get the rotate angle by three points*/
qreal  calculateAngle(QPointF point1, QPointF point2, QPointF point3);

/* get the new points after rotate with angle*/
QPointF  pointRotate(QPointF point1, QPointF point2, qreal angle);

/* the distance from a point(point3) to a line(point1, point2) */
qreal   pointToLineDistance(QPointF point1, QPointF point2, QPointF point3);

/* judge the direction of point3 of line(point1, point2) */
qreal pointLineDir(QPointF point1, QPointF point2, QPointF point3);

/*get another four points in rectangle (Top/Bottom/Left/Right) */
FourPoints getAnotherFPoints(QPointF point1, QPointF point2,
                             QPointF point3, QPointF point4);

/* handle resize of eight points in rectangle */
FourPoints resizePointPosition(QPointF point1, QPointF point2, QPointF point3, QPointF point4,
                          QPointF pos, int key, bool isShift = false);

/***************** first point1 *******************/
/* point1 in the first position */
FourPoints point1Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point1 in the second position*/
FourPoints point1Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point1 in the third position */
FourPoints point1Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point1 in the fourth position */
FourPoints point1Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point1 in the fifth position */
FourPoints point1Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point1 in the sixth position */
FourPoints point1Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point1 in the seventh position */
FourPoints point1Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);

/***************** second point2 *******************/
/* point2 in the first position */
FourPoints point2Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point2 in the second position */
FourPoints point2Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point2 in the third position */
FourPoints point2Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point2 in the fourth position */
FourPoints point2Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point2 in the fifth position */
FourPoints point2Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point2 in the sixth position */
FourPoints point2Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point2 in the seventh position */
FourPoints point2Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);

/***************** third point3 *******************/
/* point3 in the first position */
FourPoints point3Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point3 in the second position */
FourPoints point3Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point3 in the third position */
FourPoints point3Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point3 in the fourth position */
FourPoints point3Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point3 in the fifth position */
FourPoints point3Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point3 in the sixth position */
FourPoints point3Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point3 in the seventh position */
FourPoints point3Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);

/***************** fourth point4 *******************/
/* point4 in the first position */
FourPoints point4Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point4 in the second position */
FourPoints point4Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point4 in the third position */
FourPoints point4Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point4 in the fourth position */
FourPoints point4Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point4 in the fifth position */
FourPoints point4Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point4 in the sixth position */
FourPoints point4Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point4 in the seventh position */
FourPoints point4Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);

/********************** fifth point5 ************************/
/* point5 in the first position */
FourPoints point5Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point5 in the second position */
FourPoints point5Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point5 in the third position */
FourPoints point5Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point5 in the fourth position */
FourPoints point5Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point5 in the fifth position */
FourPoints point5Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point5 in the sixth position */
FourPoints point5Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point5 in the seventh position */
FourPoints point5Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);

/********************** sixth point6 ************************/
/* point6 in the first position */
FourPoints point6Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point6 in the second position */
FourPoints point6Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point6 in the third position */
FourPoints point6Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point6 in the fourth position */
FourPoints point6Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point6 in the fifth position */
FourPoints point6Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point6 in the sixth position */
FourPoints point6Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point6 in the seventh position */
FourPoints point6Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);

/********************** seventh point7 ************************/
/* point7 in the first position */
FourPoints point7Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point7 in the second position */
FourPoints point7Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point7 in the third position */
FourPoints point7Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point7 in the fourth position */
FourPoints point7Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point7 in the fifth position */
FourPoints point7Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point7 in the sixth position */
FourPoints point7Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point7 in the seventh position */
FourPoints point7Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);

/********************** eighth point8 ************************/
/* point8 in the first position */
FourPoints point8Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point8 in the second position */
FourPoints point8Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point8 in the third position */
FourPoints point8Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point8 in the fourth position */
FourPoints point8Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point8 in the fifth position */
FourPoints point8Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point8 in the sixth position */
FourPoints point8Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point8 in the seventh position */
FourPoints point8Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
#endif // CALCULATERECT_H
