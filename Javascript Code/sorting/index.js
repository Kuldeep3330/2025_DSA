// Define an array of point objects
const points = [
  { x: 3, y: 10 },
  { x: 2, y: 8 },
  { x: 5, y: 4 }
];

// Sort by y-coordinate
points.sort((p1, p2) => p1.y - p2.y);

// Print the sorted array
for (const point of points) {
  console.log(point.x, point.y);
}
