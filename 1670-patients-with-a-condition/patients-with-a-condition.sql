# Write your MySQL query statement below
select patient_id, patient_name, conditions
from patients
where conditIons like '% DIAB1%' or conditIons like 'DIAB1%'