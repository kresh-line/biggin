
select count(*) from country_languages;

select languages. language from languages , country_languages
,countries
where languages. language_id=country_languages. language_id
and country_languages. country_id= countries. country_id and
countries. name like 'South Africa';

SELECT name
FROM countries
WHERE area = (SELECT MIN(area) FROM countries);