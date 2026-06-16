from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('core', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='stdlibmodule',
            name='category',
            field=models.CharField(db_index=True, default='utilities', max_length=32),
        ),
        migrations.AddField(
            model_name='stdlibmodule',
            name='description_en',
            field=models.TextField(blank=True),
        ),
        migrations.AddField(
            model_name='stdlibmodule',
            name='description_fr',
            field=models.TextField(blank=True),
        ),
        migrations.AddField(
            model_name='stdlibmodule',
            name='has_pdf',
            field=models.BooleanField(default=False),
        ),
        migrations.AddField(
            model_name='stdlibmodule',
            name='tier',
            field=models.CharField(
                choices=[('simple', 'Simple'), ('medium', 'Medium'), ('complex', 'Complex')],
                db_index=True,
                default='simple',
                max_length=16,
            ),
        ),
        migrations.AlterModelOptions(
            name='stdlibmodule',
            options={'ordering': ['category', 'name'], 'verbose_name': 'Stdlib module'},
        ),
    ]
