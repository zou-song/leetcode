# Write your MySQL query statement below
SELECT Email FROM
(
    SELECT Email, COUNT(Email) AS Count
    FROM Person
    GROUP BY Email
) AS T
WHERE Count > 1