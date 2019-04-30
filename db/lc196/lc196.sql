# Write your MySQL query statement below
DELETE FROM Person
WHERE Id IN
(
    SELECT Id FROM
    (
        SELECT T1.Id
        FROM Person AS T1, Person AS T2
        WHERE T1.Id > T2.Id AND T1.Email = T2.Email
    ) AS TMP
)