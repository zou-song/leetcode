# Write your MySQL query statement below
SELECT Score, 
(
    SELECT COUNT(DISTINCT Score)
    FROM Scores
    WHERE Score >= LT.Score
) AS Rank
FROM Scores AS LT
ORDER BY Score DESC