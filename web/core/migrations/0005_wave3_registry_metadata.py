# Generated manually for Vague 3 package/registry metadata

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('core', '0004_stdlibmodule_descriptions'),
    ]

    operations = [
        migrations.AddField(
            model_name='package',
            name='repo_url',
            field=models.URLField(blank=True),
        ),
        migrations.AddField(
            model_name='package',
            name='method',
            field=models.CharField(blank=True, default='local', max_length=16),
        ),
        migrations.AddField(
            model_name='package',
            name='license',
            field=models.CharField(blank=True, max_length=64),
        ),
        migrations.AddField(
            model_name='package',
            name='tags',
            field=models.JSONField(blank=True, default=list),
        ),
        migrations.AddField(
            model_name='package',
            name='readme',
            field=models.TextField(blank=True),
        ),
        migrations.AddField(
            model_name='stdlibmodule',
            name='is_core',
            field=models.BooleanField(db_index=True, default=False),
        ),
        migrations.AddField(
            model_name='stdlibmodule',
            name='experimental',
            field=models.BooleanField(db_index=True, default=True),
        ),
    ]
